/*
Bullet Continuous Collision Detection and Physics Library, http://bulletphysics.org
Copyright (C) 2006 - 2011 Sony Computer Entertainment Inc. 

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

//original author: Roman Ponomarev
//cleanup by Erwin Coumans

#ifndef BT_OPENCL_UTILS_H
#define BT_OPENCL_UTILS_H

#include "btOpenCLInclude.h"


#define BT_MAX_STRING_LENGTH 1024

struct btOpenCLDeviceInfo
{
	char m_deviceName[BT_MAX_STRING_LENGTH];
	char m_deviceVendor[BT_MAX_STRING_LENGTH];
	char m_driverVersion[BT_MAX_STRING_LENGTH];
	char m_deviceExtensions[BT_MAX_STRING_LENGTH];

	cl_device_type		m_deviceType;
	cl_uint 				m_computeUnits;
	size_t 					m_workitemDims;
	size_t 					m_workItemSize[3];
	size_t 					m_image2dMaxWidth;
	size_t 					m_image2dMaxHeight;
	size_t 					m_image3dMaxWidth;
	size_t 					m_image3dMaxHeight;
	size_t 					m_image3dMaxDepth;
	size_t 					m_workgroupSize;
	cl_uint 				m_clockFrequency;
	cl_ulong				m_constantBufferSize;
	cl_ulong				m_localMemSize;
	cl_ulong				m_globalMemSize;
    cl_bool					m_errorCorrectionSupport;
	cl_device_local_mem_type m_localMemType;
	cl_uint					m_maxReadImageArgs;
	cl_uint					m_maxWriteImageArgs;



	cl_uint 				m_addressBits;
	cl_ulong				m_maxMemAllocSize;
	cl_command_queue_properties m_queueProperties;
	cl_bool					m_imageSupport;
	cl_uint					m_vecWidthChar;
	cl_uint					m_vecWidthShort;
	cl_uint					m_vecWidthInt;
	cl_uint					m_vecWidthLong;
	cl_uint					m_vecWidthFloat;
	cl_uint					m_vecWidthDouble;

};


class btOpenCLUtils
{
public:
	// CL Context optionally takes a GL context. This is a generic type because we don't really want this code
	// to have to understand GL types.
	// It is a HGLRC in _WIN32 or a GLXContext otherwise.
	static cl_context 	createContextFromType(cl_device_type deviceType, cl_int* pErrNum, void* pGLCtx = 0, void* pGLDC = 0);
	static int getNumDevices(cl_context cxMainContext);
	static cl_device_id getDevice(cl_context cxMainContext, int nr);
	static void getDeviceInfo(cl_device_id device, btOpenCLDeviceInfo& info);
	static void printDeviceInfo(cl_device_id device);

	static cl_kernel compileCLKernelFromString( cl_context clContext,const char* kernelSource, const char* kernelName, const char* additionalMacros = "" );

};



#endif // BT_OPENCL_UTILS_H
