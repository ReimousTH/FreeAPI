// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_PLANE_3D_H_INCLUDED__
#define __IRR_PLANE_3D_H_INCLUDED__

#include "irrMath.h"
#include "vector3d.h"

namespace irr
{
	namespace core
	{

		enum EIntersectionRelation3D
		{
			ISREL3D_FRONT = 0,
			ISREL3D_BACK,
			ISREL3D_PLANAR,
			ISREL3D_SPANNING,
			ISREL3D_CLIPPED
		};


		template <class T>
		class plane3d
		{
		public:

			// Constructors

			plane3d(): Normal(0,1,0) { recalculateD(vector3d<T>(0,0,0)); }

			plane3d(const vector3d<T>& MPoint, const vector3d<T>& Normal) : Normal(Normal) { recalculateD(MPoint); }

			plane3d(T px, T py, T pz, T nx, T ny, T nz) : Normal(nx, ny, nz) { recalculateD(vector3d<T>(px, py, pz)); }

			plane3d(const vector3d<T>& point1, const vector3d<T>& point2, const vector3d<T>& point3)
			{ setPlane(point1, point2, point3); }

			plane3d(const vector3d<T> & normal, const T d) : Normal(normal), D(d) { }

			// operators

			inline bool operator==(const plane3d<T>& other) const { return (equals(D, other.D) && Normal==other.Normal);}

			inline bool operator!=(const plane3d<T>& other) const { return !(*this == other);}

			// functions

			void setPlane(const vector3d<T>& point, const vector3d<T>& nvector)
			{
				Normal = nvector;
				recalculateD(point);
			}

			void setPlane(const vector3d<T>& nvect, T d)
			{
				Normal = nvect;
				D = d;
			}

			void setPlane(const vector3d<T>& point1, const vector3d<T>& point2, const vector3d<T>& point3)
			{
				// creates the plane from 3 memberpoints
				Normal = (point2 - point1).crossProduct(point3 - point1);
				Normal.normalize();

				recalculateD(point1);
			}



			bool getIntersectionWithLine(const vector3d<T>& linePoint,
				const vector3d<T>& lineVect,
				vector3d<T>& outIntersection) const
			{
				T t2 = Normal.dotProduct(lineVect);

				if (t2 == 0)
					return false;

				T t =- (Normal.dotProduct(linePoint) + D) / t2;
				outIntersection = linePoint + (lineVect * t);
				return true;
			}


			f32 getKnownIntersectionWithLine(const vector3d<T>& linePoint1,
				const vector3d<T>& linePoint2) const
			{
				vector3d<T> vect = linePoint2 - linePoint1;
				T t2 = (f32)Normal.dotProduct(vect);
				return (f32)-((Normal.dotProduct(linePoint1) + D) / t2);
			}


			bool getIntersectionWithLimitedLine(
				const vector3d<T>& linePoint1,
				const vector3d<T>& linePoint2,
				vector3d<T>& outIntersection) const
			{
				return (getIntersectionWithLine(linePoint1, linePoint2 - linePoint1, outIntersection) &&
					outIntersection.isBetweenPoints(linePoint1, linePoint2));
			}


			EIntersectionRelation3D classifyPointRelation(const vector3d<T>& point) const
			{
				const T d = Normal.dotProduct(point) + D;

				if (d < -ROUNDING_ERROR_f32)
					return ISREL3D_BACK;

				if (d > ROUNDING_ERROR_f32)
					return ISREL3D_FRONT;

				return ISREL3D_PLANAR;
			}

			void recalculateD(const vector3d<T>& MPoint)
			{
				D = - MPoint.dotProduct(Normal);
			}

			vector3d<T> getMemberPoint() const
			{
				return Normal * -D;
			}


			bool existsIntersection(const plane3d<T>& other) const
			{
				vector3d<T> cross = other.Normal.crossProduct(Normal);
				return cross.getLength() > core::ROUNDING_ERROR_f32;
			}


			bool getIntersectionWithPlane(const plane3d<T>& other,
				vector3d<T>& outLinePoint,
				vector3d<T>& outLineVect) const
			{
				const T fn00 = Normal.getLength();
				const T fn01 = Normal.dotProduct(other.Normal);
				const T fn11 = other.Normal.getLength();
				const f64 det = fn00*fn11 - fn01*fn01;

				if (fabs(det) < ROUNDING_ERROR_f64 )
					return false;

				const f64 invdet = 1.0 / det;
				const f64 fc0 = (fn11*-D + fn01*other.D) * invdet;
				const f64 fc1 = (fn00*-other.D + fn01*D) * invdet;

				outLineVect = Normal.crossProduct(other.Normal);
				outLinePoint = Normal*(T)fc0 + other.Normal*(T)fc1;
				return true;
			}

			bool getIntersectionWithPlanes(const plane3d<T>& o1,
				const plane3d<T>& o2, vector3d<T>& outPoint) const
			{
				vector3d<T> linePoint, lineVect;
				if (getIntersectionWithPlane(o1, linePoint, lineVect))
					return o2.getIntersectionWithLine(linePoint, lineVect, outPoint);

				return false;
			}


			bool isFrontFacing(const vector3d<T>& lookDirection) const
			{
				const f32 d = Normal.dotProduct(lookDirection);
				return F32_LOWER_EQUAL_0 ( d );
			}


			T getDistanceTo(const vector3d<T>& point) const
			{
				return point.dotProduct(Normal) + D;
			}

			vector3d<T> Normal;

			T D;
		};


		typedef plane3d<f32> plane3df;

		typedef plane3d<s32> plane3di;

	} // end namespace core
} // end namespace irr

#endif
