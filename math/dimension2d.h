// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_DIMENSION2D_H_INCLUDED__
#define __IRR_DIMENSION2D_H_INCLUDED__

#include "irrTypes.h"
#include "irrMath.h" // for irr::core::equals()

namespace irr
{
	namespace core
	{
		template <class T>
		class vector2d;

		template <class T>
		class dimension2d
		{
		public:
			dimension2d() : Width(0), Height(0) {}
			dimension2d(const T& width, const T& height)
				: Width(width), Height(height) {}

			dimension2d(const vector2d<T>& other); // Defined in vector2d.h

			template <class U>
			explicit dimension2d(const dimension2d<U>& other) :
			Width((T)other.Width), Height((T)other.Height) { }

			template <class U>
			dimension2d<T>& operator=(const dimension2d<U>& other)
			{
				Width = (T) other.Width;
				Height = (T) other.Height;
				return *this;
			}


			bool operator==(const dimension2d<T>& other) const
			{
				return core::equals(Width, other.Width) &&
					core::equals(Height, other.Height);
			}

			bool operator!=(const dimension2d<T>& other) const
			{
				return ! (*this == other);
			}

			bool operator==(const vector2d<T>& other) const;  // Defined in vector2d.h

			bool operator!=(const vector2d<T>& other) const
			{
				return !(*this == other);
			}

			dimension2d<T>& set(const T& width, const T& height)
			{
				Width = width;
				Height = height;
				return *this;
			}

			dimension2d<T>& operator/=(const T& scale)
			{
				Width /= scale;
				Height /= scale;
				return *this;
			}

			dimension2d<T> operator/(const T& scale) const
			{
				return dimension2d<T>(Width/scale, Height/scale);
			}

			dimension2d<T>& operator*=(const T& scale)
			{
				Width *= scale;
				Height *= scale;
				return *this;
			}

			dimension2d<T> operator*(const T& scale) const
			{
				return dimension2d<T>(Width*scale, Height*scale);
			}

			dimension2d<T>& operator+=(const dimension2d<T>& other)
			{
				Width += other.Width;
				Height += other.Height;
				return *this;
			}

			dimension2d<T> operator+(const dimension2d<T>& other) const
			{
				return dimension2d<T>(Width+other.Width, Height+other.Height);
			}

			dimension2d<T>& operator-=(const dimension2d<T>& other)
			{
				Width -= other.Width;
				Height -= other.Height;
				return *this;
			}

			dimension2d<T> operator-(const dimension2d<T>& other) const
			{
				return dimension2d<T>(Width-other.Width, Height-other.Height);
			}

			T getArea() const
			{
				return Width*Height;
			}


			dimension2d<T> getOptimalSize(
				bool requirePowerOfTwo=true,
				bool requireSquare=false,
				bool larger=true,
				u32 maxValue = 0) const
			{
				u32 i=1;
				u32 j=1;
				if (requirePowerOfTwo)
				{
					while (i<(u32)Width)
						i<<=1;
					if (!larger && i!=1 && i!=(u32)Width)
						i>>=1;
					while (j<(u32)Height)
						j<<=1;
					if (!larger && j!=1 && j!=(u32)Height)
						j>>=1;
				}
				else
				{
					i=(u32)Width;
					j=(u32)Height;
				}

				if (requireSquare)
				{
					if ((larger && (i>j)) || (!larger && (i<j)))
						j=i;
					else
						i=j;
				}

				if ( maxValue > 0 && i > maxValue)
					i = maxValue;

				if ( maxValue > 0 && j > maxValue)
					j = maxValue;

				return dimension2d<T>((T)i,(T)j);
			}


			dimension2d<T> getInterpolated(const dimension2d<T>& other, f32 d) const
			{
				f32 inv = (1.0f - d);
				return dimension2d<T>( (T)(other.Width*inv + Width*d), (T)(other.Height*inv + Height*d));
			}


			T Width;
			T Height;
		};

		typedef dimension2d<f32> dimension2df;
		typedef dimension2d<u32> dimension2du;


		typedef dimension2d<s32> dimension2di;


	} // end namespace core
} // end namespace irr

#endif

