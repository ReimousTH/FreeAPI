// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h


#ifndef __IRR_POSITION_H_INCLUDED__
#define __IRR_POSITION_H_INCLUDED__

#include "vector2d.h"

namespace irr
{
	namespace core
	{

		// Use typedefs where possible as they are more explicit...

		typedef vector2d<f32> position2df;

		typedef vector2d<s32> position2di;
	} // namespace core
} // namespace irr

// ...and use a #define to catch the rest, for (e.g.) position2d<f64>
#define position2d vector2d

#endif // __IRR_POSITION_H_INCLUDED__
