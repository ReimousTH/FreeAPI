// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and irrXML.h

#ifndef __IRR_ALLOCATOR_H_INCLUDED__
#define __IRR_ALLOCATOR_H_INCLUDED__

#include "irrTypes.h"
#include <new>
// necessary for older compilers
#include <memory.h>

namespace irr
{
	namespace core
	{

#ifdef DEBUG_CLIENTBLOCK
#undef DEBUG_CLIENTBLOCK
#define DEBUG_CLIENTBLOCK new
#endif

		template<typename T>
		class irrAllocator
		{
		public:

			virtual ~irrAllocator() {}

			T* allocate(size_t cnt)
			{
				return (T*)internal_new(cnt* sizeof(T));
			}

			void deallocate(T* ptr)
			{
				internal_delete(ptr);
			}

			void construct(T* ptr, const T&e)
			{
				new ((void*)ptr) T(e);
			}

			void destruct(T* ptr)
			{
				ptr->~T();
			}

		protected:

			virtual void* internal_new(size_t cnt)
			{
				return operator new(cnt);
			}

			virtual void internal_delete(void* ptr)
			{
				operator delete(ptr);
			}

		};



		template<typename T>
		class irrAllocatorFast
		{
		public:

			T* allocate(size_t cnt)
			{
				return (T*)operator new(cnt* sizeof(T));
			}

			void deallocate(T* ptr)
			{
				operator delete(ptr);
			}

			void construct(T* ptr, const T&e)
			{
				new ((void*)ptr) T(e);
			}

			void destruct(T* ptr)
			{
				ptr->~T();
			}
		};



#ifdef DEBUG_CLIENTBLOCK
#undef DEBUG_CLIENTBLOCK
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#endif

		enum eAllocStrategy
		{
			ALLOC_STRATEGY_SAFE    = 0,
			ALLOC_STRATEGY_DOUBLE  = 1,
			ALLOC_STRATEGY_SQRT    = 2
		};


	} // end namespace core
} // end namespace irr

#endif

