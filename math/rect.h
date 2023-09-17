// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_RECT_H_INCLUDED__
#define __IRR_RECT_H_INCLUDED__

#include "irrTypes.h"
#include "dimension2d.h"
#include "position2d.h"

namespace irr
{
	namespace core
	{


		template <class T>
		class rect
		{
		public:

			rect() : UpperLeftCorner(0,0), LowerRightCorner(0,0) {}

			rect(T x, T y, T x2, T y2)
				: UpperLeftCorner(x,y), LowerRightCorner(x2,y2) {}

			rect(const position2d<T>& upperLeft, const position2d<T>& lowerRight)
				: UpperLeftCorner(upperLeft), LowerRightCorner(lowerRight) {}

			template <class U>
			rect(const position2d<T>& pos, const dimension2d<U>& size)
				: UpperLeftCorner(pos), LowerRightCorner(pos.X + size.Width, pos.Y + size.Height) {}

			rect<T> operator+(const position2d<T>& pos) const
			{
				rect<T> ret(*this);
				return ret+=pos;
			}

			rect<T>& operator+=(const position2d<T>& pos)
			{
				UpperLeftCorner += pos;
				LowerRightCorner += pos;
				return *this;
			}

			rect<T> operator-(const position2d<T>& pos) const
			{
				rect<T> ret(*this);
				return ret-=pos;
			}

			rect<T>& operator-=(const position2d<T>& pos)
			{
				UpperLeftCorner -= pos;
				LowerRightCorner -= pos;
				return *this;
			}

			bool operator==(const rect<T>& other) const
			{
				return (UpperLeftCorner == other.UpperLeftCorner &&
					LowerRightCorner == other.LowerRightCorner);
			}

			bool operator!=(const rect<T>& other) const
			{
				return (UpperLeftCorner != other.UpperLeftCorner ||
					LowerRightCorner != other.LowerRightCorner);
			}

			bool operator<(const rect<T>& other) const
			{
				return getArea() < other.getArea();
			}

			T getArea() const
			{
				return getWidth() * getHeight();
			}


			bool isPointInside(const position2d<T>& pos) const
			{
				return (UpperLeftCorner.X <= pos.X &&
					UpperLeftCorner.Y <= pos.Y &&
					LowerRightCorner.X >= pos.X &&
					LowerRightCorner.Y >= pos.Y);
			}


			bool isRectCollided(const rect<T>& other) const
			{
				return (LowerRightCorner.Y > other.UpperLeftCorner.Y &&
					UpperLeftCorner.Y < other.LowerRightCorner.Y &&
					LowerRightCorner.X > other.UpperLeftCorner.X &&
					UpperLeftCorner.X < other.LowerRightCorner.X);
			}


			void clipAgainst(const rect<T>& other)
			{
				if (other.LowerRightCorner.X < LowerRightCorner.X)
					LowerRightCorner.X = other.LowerRightCorner.X;
				if (other.LowerRightCorner.Y < LowerRightCorner.Y)
					LowerRightCorner.Y = other.LowerRightCorner.Y;

				if (other.UpperLeftCorner.X > UpperLeftCorner.X)
					UpperLeftCorner.X = other.UpperLeftCorner.X;
				if (other.UpperLeftCorner.Y > UpperLeftCorner.Y)
					UpperLeftCorner.Y = other.UpperLeftCorner.Y;

				// correct possible invalid rect resulting from clipping
				if (UpperLeftCorner.Y > LowerRightCorner.Y)
					UpperLeftCorner.Y = LowerRightCorner.Y;
				if (UpperLeftCorner.X > LowerRightCorner.X)
					UpperLeftCorner.X = LowerRightCorner.X;
			}


			bool constrainTo(const rect<T>& other)
			{
				if (other.getWidth() < getWidth() || other.getHeight() < getHeight())
					return false;

				T diff = other.LowerRightCorner.X - LowerRightCorner.X;
				if (diff < 0)
				{
					LowerRightCorner.X += diff;
					UpperLeftCorner.X  += diff;
				}

				diff = other.LowerRightCorner.Y - LowerRightCorner.Y;
				if (diff < 0)
				{
					LowerRightCorner.Y += diff;
					UpperLeftCorner.Y  += diff;
				}

				diff = UpperLeftCorner.X - other.UpperLeftCorner.X;
				if (diff < 0)
				{
					UpperLeftCorner.X  -= diff;
					LowerRightCorner.X -= diff;
				}

				diff = UpperLeftCorner.Y - other.UpperLeftCorner.Y;
				if (diff < 0)
				{
					UpperLeftCorner.Y  -= diff;
					LowerRightCorner.Y -= diff;
				}

				return true;
			}

			T getWidth() const
			{
				return LowerRightCorner.X - UpperLeftCorner.X;
			}

			T getHeight() const
			{
				return LowerRightCorner.Y - UpperLeftCorner.Y;
			}

			void repair()
			{
				if (LowerRightCorner.X < UpperLeftCorner.X)
				{
					T t = LowerRightCorner.X;
					LowerRightCorner.X = UpperLeftCorner.X;
					UpperLeftCorner.X = t;
				}

				if (LowerRightCorner.Y < UpperLeftCorner.Y)
				{
					T t = LowerRightCorner.Y;
					LowerRightCorner.Y = UpperLeftCorner.Y;
					UpperLeftCorner.Y = t;
				}
			}


			bool isValid() const
			{
				return ((LowerRightCorner.X >= UpperLeftCorner.X) &&
					(LowerRightCorner.Y >= UpperLeftCorner.Y));
			}

			position2d<T> getCenter() const
			{
				return position2d<T>(
					(UpperLeftCorner.X + LowerRightCorner.X) / 2,
					(UpperLeftCorner.Y + LowerRightCorner.Y) / 2);
			}

			dimension2d<T> getSize() const
			{
				return dimension2d<T>(getWidth(), getHeight());
			}



			void addInternalPoint(const position2d<T>& p)
			{
				addInternalPoint(p.X, p.Y);
			}


			void addInternalPoint(T x, T y)
			{
				if (x>LowerRightCorner.X)
					LowerRightCorner.X = x;
				if (y>LowerRightCorner.Y)
					LowerRightCorner.Y = y;

				if (x<UpperLeftCorner.X)
					UpperLeftCorner.X = x;
				if (y<UpperLeftCorner.Y)
					UpperLeftCorner.Y = y;
			}

			position2d<T> UpperLeftCorner;
			position2d<T> LowerRightCorner;
		};

		typedef rect<f32> rectf;
		typedef rect<s32> recti;

	} // end namespace core
} // end namespace irr

#endif

