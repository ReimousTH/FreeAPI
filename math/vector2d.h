// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_POINT_2D_H_INCLUDED__
#define __IRR_POINT_2D_H_INCLUDED__

#include "irrMath.h"
#include "dimension2d.h"

namespace irr
{
	namespace core
	{



		template <class T>
		class vector2d
		{
		public:
			vector2d() : X(0), Y(0) {}
			vector2d(T nx, T ny) : X(nx), Y(ny) {}
			explicit vector2d(T n) : X(n), Y(n) {}
			vector2d(const vector2d<T>& other) : X(other.X), Y(other.Y) {}

			vector2d(const dimension2d<T>& other) : X(other.Width), Y(other.Height) {}

			// operators

			vector2d<T> operator-() const { return vector2d<T>(-X, -Y); }

			vector2d<T>& operator=(const vector2d<T>& other) { X = other.X; Y = other.Y; return *this; }

			vector2d<T>& operator=(const dimension2d<T>& other) { X = other.Width; Y = other.Height; return *this; }

			vector2d<T> operator+(const vector2d<T>& other) const { return vector2d<T>(X + other.X, Y + other.Y); }
			vector2d<T> operator+(const dimension2d<T>& other) const { return vector2d<T>(X + other.Width, Y + other.Height); }
			vector2d<T>& operator+=(const vector2d<T>& other) { X+=other.X; Y+=other.Y; return *this; }
			vector2d<T> operator+(const T v) const { return vector2d<T>(X + v, Y + v); }
			vector2d<T>& operator+=(const T v) { X+=v; Y+=v; return *this; }
			vector2d<T>& operator+=(const dimension2d<T>& other) { X += other.Width; Y += other.Height; return *this;  }

			vector2d<T> operator-(const vector2d<T>& other) const { return vector2d<T>(X - other.X, Y - other.Y); }
			vector2d<T> operator-(const dimension2d<T>& other) const { return vector2d<T>(X - other.Width, Y - other.Height); }
			vector2d<T>& operator-=(const vector2d<T>& other) { X-=other.X; Y-=other.Y; return *this; }
			vector2d<T> operator-(const T v) const { return vector2d<T>(X - v, Y - v); }
			vector2d<T>& operator-=(const T v) { X-=v; Y-=v; return *this; }
			vector2d<T>& operator-=(const dimension2d<T>& other) { X -= other.Width; Y -= other.Height; return *this;  }

			vector2d<T> operator*(const vector2d<T>& other) const { return vector2d<T>(X * other.X, Y * other.Y); }
			vector2d<T>& operator*=(const vector2d<T>& other) { X*=other.X; Y*=other.Y; return *this; }
			vector2d<T> operator*(const T v) const { return vector2d<T>(X * v, Y * v); }
			vector2d<T>& operator*=(const T v) { X*=v; Y*=v; return *this; }

			vector2d<T> operator/(const vector2d<T>& other) const { return vector2d<T>(X / other.X, Y / other.Y); }
			vector2d<T>& operator/=(const vector2d<T>& other) { X/=other.X; Y/=other.Y; return *this; }
			vector2d<T> operator/(const T v) const { return vector2d<T>(X / v, Y / v); }
			vector2d<T>& operator/=(const T v) { X/=v; Y/=v; return *this; }

			bool operator<=(const vector2d<T>&other) const
			{
				return  (X<other.X || core::equals(X, other.X)) ||
					(core::equals(X, other.X) && (Y<other.Y || core::equals(Y, other.Y)));
			}

			bool operator>=(const vector2d<T>&other) const
			{
				return  (X>other.X || core::equals(X, other.X)) ||
					(core::equals(X, other.X) && (Y>other.Y || core::equals(Y, other.Y)));
			}

			bool operator<(const vector2d<T>&other) const
			{
				return  (X<other.X && !core::equals(X, other.X)) ||
					(core::equals(X, other.X) && Y<other.Y && !core::equals(Y, other.Y));
			}

			bool operator>(const vector2d<T>&other) const
			{
				return  (X>other.X && !core::equals(X, other.X)) ||
					(core::equals(X, other.X) && Y>other.Y && !core::equals(Y, other.Y));
			}

			bool operator==(const vector2d<T>& other) const { return equals(other); }
			bool operator!=(const vector2d<T>& other) const { return !equals(other); }

			// functions


			bool equals(const vector2d<T>& other) const
			{
				return core::equals(X, other.X) && core::equals(Y, other.Y);
			}

			vector2d<T>& set(T nx, T ny) {X=nx; Y=ny; return *this; }
			vector2d<T>& set(const vector2d<T>& p) { X=p.X; Y=p.Y; return *this; }


			T getLength() const { return core::squareroot( X*X + Y*Y ); }


			T getLengthSQ() const { return X*X + Y*Y; }


			T dotProduct(const vector2d<T>& other) const
			{
				return X*other.X + Y*other.Y;
			}


			T getDistanceFrom(const vector2d<T>& other) const
			{
				return vector2d<T>(X - other.X, Y - other.Y).getLength();
			}


			T getDistanceFromSQ(const vector2d<T>& other) const
			{
				return vector2d<T>(X - other.X, Y - other.Y).getLengthSQ();
			}


			vector2d<T>& rotateBy(f64 degrees, const vector2d<T>& center=vector2d<T>())
			{
				degrees *= DEGTORAD64;
				const f64 cs = cos(degrees);
				const f64 sn = sin(degrees);

				X -= center.X;
				Y -= center.Y;

				set((T)(X*cs - Y*sn), (T)(X*sn + Y*cs));

				X += center.X;
				Y += center.Y;
				return *this;
			}


			vector2d<T>& normalize()
			{
				f32 length = (f32)(X*X + Y*Y);
				if ( length == 0 )
					return *this;
				length = core::reciprocal_squareroot ( length );
				X = (T)(X * length);
				Y = (T)(Y * length);
				return *this;
			}


			f64 getAngleTrig() const
			{
				if (Y == 0)
					return X < 0 ? 180 : 0;
				else
					if (X == 0)
						return Y < 0 ? 270 : 90;

				if ( Y > 0)
					if (X > 0)
						return atan((irr::f64)Y/(irr::f64)X) * RADTODEG64;
					else
						return 180.0-atan((irr::f64)Y/-(irr::f64)X) * RADTODEG64;
				else
					if (X > 0)
						return 360.0-atan(-(irr::f64)Y/(irr::f64)X) * RADTODEG64;
					else
						return 180.0+atan(-(irr::f64)Y/-(irr::f64)X) * RADTODEG64;
			}


			inline f64 getAngle() const
			{
				if (Y == 0) // corrected thanks to a suggestion by Jox
					return X < 0 ? 180 : 0;
				else if (X == 0)
					return Y < 0 ? 90 : 270;

				// don't use getLength here to avoid precision loss with s32 vectors
				// avoid floating-point trouble as sqrt(y*y) is occasionally larger than y, so clamp
				const f64 tmp = core::clamp(Y / sqrt((f64)(X*X + Y*Y)), -1.0, 1.0);
				const f64 angle = atan( core::squareroot(1 - tmp*tmp) / tmp) * RADTODEG64;

				if (X>0 && Y>0)
					return angle + 270;
				else
					if (X>0 && Y<0)
						return angle + 90;
					else
						if (X<0 && Y<0)
							return 90 - angle;
						else
							if (X<0 && Y>0)
								return 270 - angle;

				return angle;
			}


			inline f64 getAngleWith(const vector2d<T>& b) const
			{
				f64 tmp = (f64)(X*b.X + Y*b.Y);

				if (tmp == 0.0)
					return 90.0;

				tmp = tmp / core::squareroot((f64)((X*X + Y*Y) * (b.X*b.X + b.Y*b.Y)));
				if (tmp < 0.0)
					tmp = -tmp;
				if ( tmp > 1.0 ) //   avoid floating-point trouble
					tmp = 1.0;

				return atan(sqrt(1 - tmp*tmp) / tmp) * RADTODEG64;
			}


			bool isBetweenPoints(const vector2d<T>& begin, const vector2d<T>& end) const
			{
				if (begin.X != end.X)
				{
					return ((begin.X <= X && X <= end.X) ||
						(begin.X >= X && X >= end.X));
				}
				else
				{
					return ((begin.Y <= Y && Y <= end.Y) ||
						(begin.Y >= Y && Y >= end.Y));
				}
			}


			vector2d<T> getInterpolated(const vector2d<T>& other, f64 d) const
			{
				f64 inv = 1.0f - d;
				return vector2d<T>((T)(other.X*inv + X*d), (T)(other.Y*inv + Y*d));
			}


			vector2d<T> getInterpolated_quadratic(const vector2d<T>& v2, const vector2d<T>& v3, f64 d) const
			{
				// this*(1-d)*(1-d) + 2 * v2 * (1-d) + v3 * d * d;
				const f64 inv = 1.0f - d;
				const f64 mul0 = inv * inv;
				const f64 mul1 = 2.0f * d * inv;
				const f64 mul2 = d * d;

				return vector2d<T> ( (T)(X * mul0 + v2.X * mul1 + v3.X * mul2),
					(T)(Y * mul0 + v2.Y * mul1 + v3.Y * mul2));
			}


			vector2d<T>& interpolate(const vector2d<T>& a, const vector2d<T>& b, f64 d)
			{
				X = (T)((f64)b.X + ( ( a.X - b.X ) * d ));
				Y = (T)((f64)b.Y + ( ( a.Y - b.Y ) * d ));
				return *this;
			}

			T X;

			T Y;
		};

		typedef vector2d<f32> vector2df;

		typedef vector2d<s32> vector2di;

		template<class S, class T>
		vector2d<T> operator*(const S scalar, const vector2d<T>& vector) { return vector*scalar; }

		// These methods are declared in dimension2d, but need definitions of vector2d
		template<class T>
		dimension2d<T>::dimension2d(const vector2d<T>& other) : Width(other.X), Height(other.Y) { }

		template<class T>
		bool dimension2d<T>::operator==(const vector2d<T>& other) const { return Width == other.X && Height == other.Y; }

	} // end namespace core
} // end namespace irr

#endif
