// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_COMPILE_CONFIG_H_INCLUDED__
#define __IRR_COMPILE_CONFIG_H_INCLUDED__

#define IRRLICHT_VERSION_MAJOR 1
#define IRRLICHT_VERSION_MINOR 8
#define IRRLICHT_VERSION_REVISION 3
// This flag will be defined only in SVN, the official release code will have
// it undefined
//#define IRRLICHT_VERSION_SVN -alpha
#define IRRLICHT_SDK_VERSION "1.8.3"

#include <stdio.h> // TODO: Although included elsewhere this is required at least for mingw





//#define _IRR_COMPILE_WITH_SDL_DEVICE_
#ifdef NO_IRR_COMPILE_WITH_SDL_DEVICE_
#undef _IRR_COMPILE_WITH_SDL_DEVICE_
#endif

#define _IRR_COMPILE_WITH_CONSOLE_DEVICE_
#ifdef NO_IRR_COMPILE_WITH_CONSOLE_DEVICE_
#undef _IRR_COMPILE_WITH_CONSOLE_DEVICE_
#endif

// The windows platform and API support SDL and WINDOW device
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define _IRR_WINDOWS_
#define _IRR_WINDOWS_API_
#define _IRR_COMPILE_WITH_WINDOWS_DEVICE_
#endif

#if defined(_WIN32_WCE)
#define _IRR_WINDOWS_
#define _IRR_WINDOWS_API_
#define _IRR_WINDOWS_CE_PLATFORM_
#define _IRR_COMPILE_WITH_WINDOWS_CE_DEVICE_
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1300)
#  error "Only Microsoft Visual Studio 7.0 and later are supported."
#endif

// XBox only suppots the native Window stuff
#if defined(_XBOX)
#undef _IRR_WINDOWS_
#define _IRR_XBOX_PLATFORM_
#define _IRR_WINDOWS_API_
//#define _IRR_COMPILE_WITH_WINDOWS_DEVICE_
#undef _IRR_COMPILE_WITH_WINDOWS_DEVICE_
//#define _IRR_COMPILE_WITH_SDL_DEVICE_

#include <xtl.h>
#endif

#if defined(__APPLE__) || defined(MACOSX)
#if !defined(MACOSX)
#define MACOSX // legacy support
#endif
#define _IRR_OSX_PLATFORM_
#define _IRR_COMPILE_WITH_OSX_DEVICE_
#endif

#if !defined(_IRR_WINDOWS_API_) && !defined(_IRR_OSX_PLATFORM_)
#ifndef _IRR_SOLARIS_PLATFORM_
#define _IRR_LINUX_PLATFORM_
#endif
#define _IRR_POSIX_API_
#define _IRR_COMPILE_WITH_X11_DEVICE_
#endif


#define _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
#ifdef NO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_
#undef _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
#endif


#define _IRR_MATERIAL_MAX_TEXTURES_ 4


#if defined(_IRR_WINDOWS_API_) && (!defined(__GNUC__) || defined(IRR_COMPILE_WITH_DX9_DEV_PACK))


#define _IRR_COMPILE_WITH_DIRECTINPUT_JOYSTICK_
#ifdef NO_IRR_COMPILE_WITH_DIRECTINPUT_JOYSTICK_
#undef _IRR_COMPILE_WITH_DIRECTINPUT_JOYSTICK_
#endif
// can't get this to compile currently under borland, can be removed if someone has a better solution
#if defined(__BORLANDC__)
#undef _IRR_COMPILE_WITH_DIRECTINPUT_JOYSTICK_
#endif

// #define _IRR_COMPILE_WITH_DIRECT3D_8_
#define _IRR_COMPILE_WITH_DIRECT3D_9_

#ifdef NO_IRR_COMPILE_WITH_DIRECT3D_8_
#undef _IRR_COMPILE_WITH_DIRECT3D_8_
#endif
#ifdef NO_IRR_COMPILE_WITH_DIRECT3D_9_
#undef _IRR_COMPILE_WITH_DIRECT3D_9_
#endif

#endif


#define _IRR_COMPILE_WITH_OPENGL_
#ifdef NO_IRR_COMPILE_WITH_OPENGL_
#undef _IRR_COMPILE_WITH_OPENGL_
#endif


#define _IRR_COMPILE_WITH_SOFTWARE_
#ifdef NO_IRR_COMPILE_WITH_SOFTWARE_
#undef _IRR_COMPILE_WITH_SOFTWARE_
#endif


#define _IRR_COMPILE_WITH_BURNINGSVIDEO_
#ifdef NO_IRR_COMPILE_WITH_BURNINGSVIDEO_
#undef _IRR_COMPILE_WITH_BURNINGSVIDEO_
#endif


// Only used in LinuxDevice.
#define _IRR_COMPILE_WITH_X11_
#ifdef NO_IRR_COMPILE_WITH_X11_
#undef _IRR_COMPILE_WITH_X11_
#endif


#if !defined(_IRR_OSX_PLATFORM_) && !defined(_IRR_SOLARIS_PLATFORM_)
#define _IRR_OPENGL_USE_EXTPOINTER_
#endif

#if defined(_IRR_LINUX_PLATFORM_) && defined(_IRR_COMPILE_WITH_X11_)
#define _IRR_LINUX_X11_VIDMODE_
//#define _IRR_LINUX_X11_RANDR_
#ifdef NO_IRR_LINUX_X11_VIDMODE_
#undef _IRR_LINUX_X11_VIDMODE_
#endif
#ifdef NO_IRR_LINUX_X11_RANDR_
#undef _IRR_LINUX_X11_RANDR_
#endif

//#define _IRR_LINUX_XCURSOR_
#ifdef NO_IRR_LINUX_XCURSOR_
#undef _IRR_LINUX_XCURSOR_
#endif

#endif


#define _IRR_COMPILE_WITH_GUI_
#ifdef NO_IRR_COMPILE_WITH_GUI_
#undef _IRR_COMPILE_WITH_GUI_
#endif


//#define _IRR_WCHAR_FILESYSTEM
#ifdef NO_IRR_WCHAR_FILESYSTEM
#undef _IRR_WCHAR_FILESYSTEM
#endif


#define _IRR_COMPILE_WITH_LIBJPEG_
#ifdef NO_IRR_COMPILE_WITH_LIBJPEG_
#undef _IRR_COMPILE_WITH_LIBJPEG_
#endif


#define _IRR_USE_NON_SYSTEM_JPEG_LIB_
#ifdef NO_IRR_USE_NON_SYSTEM_JPEG_LIB_
#undef _IRR_USE_NON_SYSTEM_JPEG_LIB_
#endif


#define _IRR_COMPILE_WITH_LIBPNG_
#ifdef NO_IRR_COMPILE_WITH_LIBPNG_
#undef _IRR_COMPILE_WITH_LIBPNG_
#endif


#define _IRR_USE_NON_SYSTEM_LIB_PNG_
#ifdef NO_IRR_USE_NON_SYSTEM_LIB_PNG_
#undef _IRR_USE_NON_SYSTEM_LIB_PNG_
#endif


#define _IRR_D3D_NO_SHADER_DEBUGGING
#ifdef NO_IRR_D3D_NO_SHADER_DEBUGGING
#undef _IRR_D3D_NO_SHADER_DEBUGGING
#endif


//#define _IRR_D3D_USE_LEGACY_HLSL_COMPILER
#ifdef NO_IRR_D3D_USE_LEGACY_HLSL_COMPILER
#undef _IRR_D3D_USE_LEGACY_HLSL_COMPILER
#endif

//#define _IRR_COMPILE_WITH_CG_
#ifdef NO_IRR_COMPILE_WITH_CG_
#undef _IRR_COMPILE_WITH_CG_
#endif
#if !defined(_IRR_COMPILE_WITH_OPENGL_) && !defined(_IRR_COMPILE_WITH_DIRECT3D_9_)
#undef _IRR_COMPILE_WITH_CG_
#endif


#undef _IRR_USE_NVIDIA_PERFHUD_


#define BURNINGVIDEO_RENDERER_BEAUTIFUL
//#define BURNINGVIDEO_RENDERER_FAST
//#define BURNINGVIDEO_RENDERER_ULTRA_FAST
//#define BURNINGVIDEO_RENDERER_CE

//#define IGNORE_DEPRECATED_WARNING


#define _IRR_COMPILE_WITH_IRR_SCENE_LOADER_
#ifdef NO_IRR_COMPILE_WITH_IRR_SCENE_LOADER_
#undef _IRR_COMPILE_WITH_IRR_SCENE_LOADER_
#endif


#define _IRR_COMPILE_WITH_SKINNED_MESH_SUPPORT_
#ifdef NO_IRR_COMPILE_WITH_SKINNED_MESH_SUPPORT_
#undef _IRR_COMPILE_WITH_SKINNED_MESH_SUPPORT_
#endif

#ifdef _IRR_COMPILE_WITH_SKINNED_MESH_SUPPORT_

#define _IRR_COMPILE_WITH_B3D_LOADER_
#ifdef NO_IRR_COMPILE_WITH_B3D_LOADER_
#undef _IRR_COMPILE_WITH_B3D_LOADER_
#endif

#define _IRR_COMPILE_WITH_MS3D_LOADER_
#ifdef NO_IRR_COMPILE_WITH_MS3D_LOADER_
#undef _IRR_COMPILE_WITH_MS3D_LOADER_
#endif

#define _IRR_COMPILE_WITH_X_LOADER_
#ifdef NO_IRR_COMPILE_WITH_X_LOADER_
#undef _IRR_COMPILE_WITH_X_LOADER_
#endif

#define _IRR_COMPILE_WITH_OGRE_LOADER_
#ifdef NO_IRR_COMPILE_WITH_OGRE_LOADER_
#undef _IRR_COMPILE_WITH_OGRE_LOADER_
#endif
#endif  // _IRR_COMPILE_WITH_SKINNED_MESH_SUPPORT_

#define _IRR_COMPILE_WITH_IRR_MESH_LOADER_
#ifdef NO_IRR_COMPILE_WITH_IRR_MESH_LOADER_
#undef _IRR_COMPILE_WITH_IRR_MESH_LOADER_
#endif

#define _IRR_COMPILE_WITH_HALFLIFE_LOADER_
#ifdef NO_IRR_COMPILE_WITH_HALFLIFE_LOADER_
#undef _IRR_COMPILE_WITH_HALFLIFE_LOADER_
#endif

#define _IRR_COMPILE_WITH_MD2_LOADER_
#ifdef NO_IRR_COMPILE_WITH_MD2_LOADER_
#undef _IRR_COMPILE_WITH_MD2_LOADER_
#endif

#define _IRR_COMPILE_WITH_MD3_LOADER_
#ifdef NO_IRR_COMPILE_WITH_MD3_LOADER_
#undef _IRR_COMPILE_WITH_MD3_LOADER_
#endif

#define _IRR_COMPILE_WITH_3DS_LOADER_
#ifdef NO_IRR_COMPILE_WITH_3DS_LOADER_
#undef _IRR_COMPILE_WITH_3DS_LOADER_
#endif

#define _IRR_COMPILE_WITH_COLLADA_LOADER_
#ifdef NO_IRR_COMPILE_WITH_COLLADA_LOADER_
#undef _IRR_COMPILE_WITH_COLLADA_LOADER_
#endif

#define _IRR_COMPILE_WITH_CSM_LOADER_
#ifdef NO_IRR_COMPILE_WITH_CSM_LOADER_
#undef _IRR_COMPILE_WITH_CSM_LOADER_
#endif

#define _IRR_COMPILE_WITH_BSP_LOADER_
#ifdef NO_IRR_COMPILE_WITH_BSP_LOADER_
#undef _IRR_COMPILE_WITH_BSP_LOADER_
#endif

#define _IRR_COMPILE_WITH_DMF_LOADER_
#ifdef NO_IRR_COMPILE_WITH_DMF_LOADER_
#undef _IRR_COMPILE_WITH_DMF_LOADER_
#endif

#define _IRR_COMPILE_WITH_LMTS_LOADER_
#ifdef NO_IRR_COMPILE_WITH_LMTS_LOADER_
#undef _IRR_COMPILE_WITH_LMTS_LOADER_
#endif

#define _IRR_COMPILE_WITH_MY3D_LOADER_
#ifdef NO_IRR_COMPILE_WITH_MY3D_LOADER_
#undef _IRR_COMPILE_WITH_MY3D_LOADER_
#endif

#define _IRR_COMPILE_WITH_OBJ_LOADER_
#ifdef NO_IRR_COMPILE_WITH_OBJ_LOADER_
#undef _IRR_COMPILE_WITH_OBJ_LOADER_
#endif

#define _IRR_COMPILE_WITH_OCT_LOADER_
#ifdef NO_IRR_COMPILE_WITH_OCT_LOADER_
#undef _IRR_COMPILE_WITH_OCT_LOADER_
#endif

#define _IRR_COMPILE_WITH_LWO_LOADER_
#ifdef NO_IRR_COMPILE_WITH_LWO_LOADER_
#undef _IRR_COMPILE_WITH_LWO_LOADER_
#endif

#define _IRR_COMPILE_WITH_STL_LOADER_
#ifdef NO_IRR_COMPILE_WITH_STL_LOADER_
#undef _IRR_COMPILE_WITH_STL_LOADER_
#endif

#define _IRR_COMPILE_WITH_PLY_LOADER_
#ifdef NO_IRR_COMPILE_WITH_PLY_LOADER_
#undef _IRR_COMPILE_WITH_PLY_LOADER_
#endif

#define _IRR_COMPILE_WITH_SMF_LOADER_
#ifdef NO_IRR_COMPILE_WITH_SMF_LOADER_
#undef _IRR_COMPILE_WITH_SMF_LOADER_
#endif

#define _IRR_COMPILE_WITH_IRR_WRITER_
#ifdef NO_IRR_COMPILE_WITH_IRR_WRITER_
#undef _IRR_COMPILE_WITH_IRR_WRITER_
#endif

#define _IRR_COMPILE_WITH_COLLADA_WRITER_
#ifdef NO_IRR_COMPILE_WITH_COLLADA_WRITER_
#undef _IRR_COMPILE_WITH_COLLADA_WRITER_
#endif

#define _IRR_COMPILE_WITH_STL_WRITER_
#ifdef NO_IRR_COMPILE_WITH_STL_WRITER_
#undef _IRR_COMPILE_WITH_STL_WRITER_
#endif

#define _IRR_COMPILE_WITH_OBJ_WRITER_
#ifdef NO_IRR_COMPILE_WITH_OBJ_WRITER_
#undef _IRR_COMPILE_WITH_OBJ_WRITER_
#endif

#define _IRR_COMPILE_WITH_PLY_WRITER_
#ifdef NO_IRR_COMPILE_WITH_PLY_WRITER_
#undef _IRR_COMPILE_WITH_PLY_WRITER_
#endif

#define _IRR_COMPILE_WITH_BMP_LOADER_
#ifdef NO_IRR_COMPILE_WITH_BMP_LOADER_
#undef _IRR_COMPILE_WITH_BMP_LOADER_
#endif

#define _IRR_COMPILE_WITH_JPG_LOADER_
#ifdef NO_IRR_COMPILE_WITH_JPG_LOADER_
#undef _IRR_COMPILE_WITH_JPG_LOADER_
#endif

#define _IRR_COMPILE_WITH_PCX_LOADER_
#ifdef NO_IRR_COMPILE_WITH_PCX_LOADER_
#undef _IRR_COMPILE_WITH_PCX_LOADER_
#endif

#define _IRR_COMPILE_WITH_PNG_LOADER_
#ifdef NO_IRR_COMPILE_WITH_PNG_LOADER_
#undef _IRR_COMPILE_WITH_PNG_LOADER_
#endif

#define _IRR_COMPILE_WITH_PPM_LOADER_
#ifdef NO_IRR_COMPILE_WITH_PPM_LOADER_
#undef _IRR_COMPILE_WITH_PPM_LOADER_
#endif

#define _IRR_COMPILE_WITH_PSD_LOADER_
#ifdef NO_IRR_COMPILE_WITH_PSD_LOADER_
#undef _IRR_COMPILE_WITH_PSD_LOADER_
#endif

// Outcommented because
// a) it doesn't compile on 64-bit currently
// b) anyone enabling it should be aware that S3TC compression algorithm which might be used in that loader
// is patented in the US by S3 and they do collect license fees when it's used in applications.
// So if you are unfortunate enough to develop applications for US market and their broken patent system be careful.
// #define _IRR_COMPILE_WITH_DDS_LOADER_
#ifdef NO_IRR_COMPILE_WITH_DDS_LOADER_
#undef _IRR_COMPILE_WITH_DDS_LOADER_
#endif

#define _IRR_COMPILE_WITH_TGA_LOADER_
#ifdef NO_IRR_COMPILE_WITH_TGA_LOADER_
#undef _IRR_COMPILE_WITH_TGA_LOADER_
#endif

#define _IRR_COMPILE_WITH_WAL_LOADER_
#ifdef NO_IRR_COMPILE_WITH_WAL_LOADER_
#undef _IRR_COMPILE_WITH_WAL_LOADER_
#endif

#define _IRR_COMPILE_WITH_LMP_LOADER_
#ifdef NO_IRR_COMPILE_WITH_LMP_LOADER_
#undef _IRR_COMPILE_WITH_LMP_LOADER_
#endif

#define _IRR_COMPILE_WITH_RGB_LOADER_
#ifdef NO_IRR_COMPILE_WITH_RGB_LOADER_
#undef _IRR_COMPILE_WITH_RGB_LOADER_
#endif

#define _IRR_COMPILE_WITH_BMP_WRITER_
#ifdef NO_IRR_COMPILE_WITH_BMP_WRITER_
#undef _IRR_COMPILE_WITH_BMP_WRITER_
#endif

#define _IRR_COMPILE_WITH_JPG_WRITER_
#ifdef NO_IRR_COMPILE_WITH_JPG_WRITER_
#undef _IRR_COMPILE_WITH_JPG_WRITER_
#endif

#define _IRR_COMPILE_WITH_PCX_WRITER_
#ifdef NO_IRR_COMPILE_WITH_PCX_WRITER_
#undef _IRR_COMPILE_WITH_PCX_WRITER_
#endif

#define _IRR_COMPILE_WITH_PNG_WRITER_
#ifdef NO_IRR_COMPILE_WITH_PNG_WRITER_
#undef _IRR_COMPILE_WITH_PNG_WRITER_
#endif

#define _IRR_COMPILE_WITH_PPM_WRITER_
#ifdef NO_IRR_COMPILE_WITH_PPM_WRITER_
#undef _IRR_COMPILE_WITH_PPM_WRITER_
#endif

#define _IRR_COMPILE_WITH_PSD_WRITER_
#ifdef NO_IRR_COMPILE_WITH_PSD_WRITER_
#undef _IRR_COMPILE_WITH_PSD_WRITER_
#endif

#define _IRR_COMPILE_WITH_TGA_WRITER_
#ifdef NO_IRR_COMPILE_WITH_TGA_WRITER_
#undef _IRR_COMPILE_WITH_TGA_WRITER_
#endif


#define __IRR_COMPILE_WITH_ZIP_ARCHIVE_LOADER_
#ifdef NO__IRR_COMPILE_WITH_ZIP_ARCHIVE_LOADER_
#undef __IRR_COMPILE_WITH_ZIP_ARCHIVE_LOADER_
#endif
#ifdef __IRR_COMPILE_WITH_ZIP_ARCHIVE_LOADER_


#define _IRR_COMPILE_WITH_ZLIB_
#ifdef NO_IRR_COMPILE_WITH_ZLIB_
#undef _IRR_COMPILE_WITH_ZLIB_
#endif


#define _IRR_USE_NON_SYSTEM_ZLIB_
#ifdef NO_IRR_USE_NON_SYSTEM_ZLIB_
#undef _IRR_USE_NON_SYSTEM_ZLIB_
#endif

#define _IRR_COMPILE_WITH_ZIP_ENCRYPTION_
#ifdef NO_IRR_COMPILE_WITH_ZIP_ENCRYPTION_
#undef _IRR_COMPILE_WITH_ZIP_ENCRYPTION_
#endif


#define _IRR_COMPILE_WITH_BZIP2_
#ifdef NO_IRR_COMPILE_WITH_BZIP2_
#undef _IRR_COMPILE_WITH_BZIP2_
#endif


#define _IRR_USE_NON_SYSTEM_BZLIB_
#ifdef NO_IRR_USE_NON_SYSTEM_BZLIB_
#undef _IRR_USE_NON_SYSTEM_BZLIB_
#endif


#define _IRR_COMPILE_WITH_LZMA_
#ifdef NO_IRR_COMPILE_WITH_LZMA_
#undef _IRR_COMPILE_WITH_LZMA_
#endif
#endif

#define __IRR_COMPILE_WITH_MOUNT_ARCHIVE_LOADER_
#ifdef NO__IRR_COMPILE_WITH_MOUNT_ARCHIVE_LOADER_
#undef __IRR_COMPILE_WITH_MOUNT_ARCHIVE_LOADER_
#endif

#define __IRR_COMPILE_WITH_PAK_ARCHIVE_LOADER_
#ifdef NO__IRR_COMPILE_WITH_PAK_ARCHIVE_LOADER_
#undef __IRR_COMPILE_WITH_PAK_ARCHIVE_LOADER_
#endif

#define __IRR_COMPILE_WITH_NPK_ARCHIVE_LOADER_
#ifdef NO__IRR_COMPILE_WITH_NPK_ARCHIVE_LOADER_
#undef __IRR_COMPILE_WITH_NPK_ARCHIVE_LOADER_
#endif

#define __IRR_COMPILE_WITH_TAR_ARCHIVE_LOADER_
#ifdef NO__IRR_COMPILE_WITH_TAR_ARCHIVE_LOADER_
#undef __IRR_COMPILE_WITH_TAR_ARCHIVE_LOADER_
#endif

#define __IRR_COMPILE_WITH_WAD_ARCHIVE_LOADER_
#ifdef NO__IRR_COMPILE_WITH_WAD_ARCHIVE_LOADER_
#undef __IRR_COMPILE_WITH_WAD_ARCHIVE_LOADER_
#endif


#if !defined(_IRR_OSX_PLATFORM_) && !defined(_IRR_SOLARIS_PLATFORM_)
//#define IRRLICHT_FAST_MATH
#ifdef NO_IRRLICHT_FAST_MATH
#undef IRRLICHT_FAST_MATH
#endif
#endif

// Some cleanup and standard stuff

#ifdef _IRR_WINDOWS_API_

// To build Irrlicht as a static library, you must define _IRR_STATIC_LIB_ in both the
// Irrlicht build, *and* in the user application, before #including <irrlicht.h>
#ifndef _IRR_STATIC_LIB_
#ifdef IRRLICHT_EXPORTS
#define IRRLICHT_API __declspec(dllexport)
#else
#define IRRLICHT_API __declspec(dllimport)
#endif // IRRLICHT_EXPORT
#else
#define IRRLICHT_API
#endif // _IRR_STATIC_LIB_

// Declare the calling convention.
#if defined(_STDCALL_SUPPORTED)
#define IRRCALLCONV __stdcall
#else
#define IRRCALLCONV __cdecl
#endif // STDCALL_SUPPORTED

#else // _IRR_WINDOWS_API_

// Force symbol export in shared libraries built with gcc.
#if (__GNUC__ >= 4) && !defined(_IRR_STATIC_LIB_) && defined(IRRLICHT_EXPORTS)
#define IRRLICHT_API __attribute__ ((visibility("default")))
#else
#define IRRLICHT_API
#endif

#define IRRCALLCONV

#endif // _IRR_WINDOWS_API_

// We need to disable DIRECT3D9 support for Visual Studio 6.0 because
// those $%&$!! disabled support for it since Dec. 2004 and users are complaining
// about linker errors. Comment this out only if you are knowing what you are
// doing. (Which means you have an old DX9 SDK and VisualStudio6).
#ifdef _MSC_VER
#if (_MSC_VER < 1300 && !defined(__GNUC__))
#undef _IRR_COMPILE_WITH_DIRECT3D_9_
#pragma message("Compiling Irrlicht with Visual Studio 6.0, support for DX9 is disabled.")
#endif
#endif

// XBox does not have OpenGL or DirectX9
#if defined(_IRR_XBOX_PLATFORM_)
#undef _IRR_COMPILE_WITH_OPENGL_
#undef _IRR_COMPILE_WITH_DIRECT3D_9_
#endif

#if defined(_WIN32_WCE)
#undef _IRR_COMPILE_WITH_OPENGL_
#undef _IRR_COMPILE_WITH_DIRECT3D_8_
#undef _IRR_COMPILE_WITH_DIRECT3D_9_

#undef BURNINGVIDEO_RENDERER_BEAUTIFUL
#undef BURNINGVIDEO_RENDERER_FAST
#undef BURNINGVIDEO_RENDERER_ULTRA_FAST
#define BURNINGVIDEO_RENDERER_CE

#undef _IRR_COMPILE_WITH_WINDOWS_DEVICE_
#define _IRR_COMPILE_WITH_WINDOWS_CE_DEVICE_
//#define _IRR_WCHAR_FILESYSTEM

#undef _IRR_COMPILE_WITH_IRR_MESH_LOADER_
//#undef _IRR_COMPILE_WITH_MD2_LOADER_
#undef _IRR_COMPILE_WITH_MD3_LOADER_
#undef _IRR_COMPILE_WITH_3DS_LOADER_
#undef _IRR_COMPILE_WITH_COLLADA_LOADER_
#undef _IRR_COMPILE_WITH_CSM_LOADER_
#undef _IRR_COMPILE_WITH_BSP_LOADER_
#undef _IRR_COMPILE_WITH_DMF_LOADER_
#undef _IRR_COMPILE_WITH_LMTS_LOADER_
#undef _IRR_COMPILE_WITH_MY3D_LOADER_
#undef _IRR_COMPILE_WITH_OBJ_LOADER_
#undef _IRR_COMPILE_WITH_OCT_LOADER_
#undef _IRR_COMPILE_WITH_OGRE_LOADER_
#undef _IRR_COMPILE_WITH_LWO_LOADER_
#undef _IRR_COMPILE_WITH_STL_LOADER_
#undef _IRR_COMPILE_WITH_IRR_WRITER_
#undef _IRR_COMPILE_WITH_COLLADA_WRITER_
#undef _IRR_COMPILE_WITH_STL_WRITER_
#undef _IRR_COMPILE_WITH_OBJ_WRITER_
//#undef _IRR_COMPILE_WITH_BMP_LOADER_
//#undef _IRR_COMPILE_WITH_JPG_LOADER_
#undef _IRR_COMPILE_WITH_PCX_LOADER_
//#undef _IRR_COMPILE_WITH_PNG_LOADER_
#undef _IRR_COMPILE_WITH_PPM_LOADER_
#undef _IRR_COMPILE_WITH_PSD_LOADER_
//#undef _IRR_COMPILE_WITH_TGA_LOADER_
#undef _IRR_COMPILE_WITH_WAL_LOADER_
#undef _IRR_COMPILE_WITH_BMP_WRITER_
#undef _IRR_COMPILE_WITH_JPG_WRITER_
#undef _IRR_COMPILE_WITH_PCX_WRITER_
#undef _IRR_COMPILE_WITH_PNG_WRITER_
#undef _IRR_COMPILE_WITH_PPM_WRITER_
#undef _IRR_COMPILE_WITH_PSD_WRITER_
#undef _IRR_COMPILE_WITH_TGA_WRITER_

#endif

#ifndef _IRR_WINDOWS_API_
#undef _IRR_WCHAR_FILESYSTEM
#endif

#if defined(__sparc__) || defined(__sun__)
#define __BIG_ENDIAN__
#endif

#if defined(_IRR_SOLARIS_PLATFORM_)
#undef _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
#endif

#define __IRR_HAS_S64
#ifdef NO__IRR_HAS_S64
#undef __IRR_HAS_S64
#endif

#if defined(__BORLANDC__)
#include <tchar.h>

// Borland 5.5.1 does not have _strcmpi defined
#if __BORLANDC__ == 0x551
//    #define _strcmpi strcmpi
#undef _tfinddata_t
#undef _tfindfirst
#undef _tfindnext

#define _tfinddata_t __tfinddata_t
#define _tfindfirst  __tfindfirst
#define _tfindnext   __tfindnext
typedef long intptr_t;
#endif

#endif

#ifdef _DEBUG

// NOTE: Those attributes were used always until 1.8.0 and became a global define for 1.8.1
// which is only enabled in debug because it had a large (sometimes >5%) impact on speed.
// A better solution in the long run is to break the interface and remove _all_ attribute
// access in functions like CSceneManager::drawAll and instead put that information in some
// own struct/class or in CSceneManager.
// See http://irrlicht.sourceforge.net/forum/viewtopic.php?f=2&t=48211 for the discussion.
#define _IRR_SCENEMANAGER_DEBUG
#ifdef NO_IRR_SCENEMANAGER_DEBUG
#undef _IRR_SCENEMANAGER_DEBUG
#endif
#endif

#endif // __IRR_COMPILE_CONFIG_H_INCLUDED__

