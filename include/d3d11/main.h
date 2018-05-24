/*
    CONTRIBUTORS:
        Sean Pesce

*/
#pragma once

#ifndef SP_D3D11_DLL_DATA_MAIN_H_
#define SP_D3D11_DLL_DATA_MAIN_H_

#include "D3D11.h"
#include "Windows.Graphics.DirectX.Direct3D11.interop.h"

namespace d3d11 {

constexpr const char* filename = "d3d11.dll";
const size_t func_count = 51; // func_count = 42 on Windows 7
enum func_index { CreateDirect3D11DeviceFromDXGIDevice_i, CreateDirect3D11SurfaceFromDXGISurface_i, D3D11CoreCreateDevice_i, D3D11CoreCreateLayeredDevice_i, D3D11CoreGetLayeredDeviceSize_i, D3D11CoreRegisterLayers_i, D3D11CreateDevice_i, D3D11CreateDeviceAndSwapChain_i, D3D11CreateDeviceForD3D12_i, D3D11On12CreateDevice_i, D3DKMTCloseAdapter_i, D3DKMTCreateAllocation_i, D3DKMTCreateContext_i, D3DKMTCreateDevice_i, D3DKMTCreateSynchronizationObject_i, D3DKMTDestroyAllocation_i, D3DKMTDestroyContext_i, D3DKMTDestroyDevice_i, D3DKMTDestroySynchronizationObject_i, D3DKMTEscape_i, D3DKMTGetContextSchedulingPriority_i, D3DKMTGetDeviceState_i, D3DKMTGetDisplayModeList_i, D3DKMTGetMultisampleMethodList_i, D3DKMTGetRuntimeData_i, D3DKMTGetSharedPrimaryHandle_i, D3DKMTLock_i, D3DKMTOpenAdapterFromHdc_i, D3DKMTOpenResource_i, D3DKMTPresent_i, D3DKMTQueryAdapterInfo_i, D3DKMTQueryAllocationResidency_i, D3DKMTQueryResourceInfo_i, D3DKMTRender_i, D3DKMTSetAllocationPriority_i, D3DKMTSetContextSchedulingPriority_i, D3DKMTSetDisplayMode_i, D3DKMTSetDisplayPrivateDriverFormat_i, D3DKMTSetGammaRamp_i, D3DKMTSetVidPnSourceOwner_i, D3DKMTSignalSynchronizationObject_i, D3DKMTUnlock_i, D3DKMTWaitForSynchronizationObject_i, D3DKMTWaitForVerticalBlankEvent_i, D3DPerformance_BeginEvent_i, D3DPerformance_EndEvent_i, D3DPerformance_GetStatus_i, D3DPerformance_SetMarker_i, EnableFeatureLevelUpgrade_i, OpenAdapter10_i, OpenAdapter10_2_i };
constexpr const char* func_names[func_count] = { "CreateDirect3D11DeviceFromDXGIDevice", "CreateDirect3D11SurfaceFromDXGISurface", "D3D11CoreCreateDevice", "D3D11CoreCreateLayeredDevice", "D3D11CoreGetLayeredDeviceSize", "D3D11CoreRegisterLayers", "D3D11CreateDevice", "D3D11CreateDeviceAndSwapChain", "D3D11CreateDeviceForD3D12", "D3D11On12CreateDevice", "D3DKMTCloseAdapter", "D3DKMTCreateAllocation", "D3DKMTCreateContext", "D3DKMTCreateDevice", "D3DKMTCreateSynchronizationObject", "D3DKMTDestroyAllocation", "D3DKMTDestroyContext", "D3DKMTDestroyDevice", "D3DKMTDestroySynchronizationObject", "D3DKMTEscape", "D3DKMTGetContextSchedulingPriority", "D3DKMTGetDeviceState", "D3DKMTGetDisplayModeList", "D3DKMTGetMultisampleMethodList", "D3DKMTGetRuntimeData", "D3DKMTGetSharedPrimaryHandle", "D3DKMTLock", "D3DKMTOpenAdapterFromHdc", "D3DKMTOpenResource", "D3DKMTPresent", "D3DKMTQueryAdapterInfo", "D3DKMTQueryAllocationResidency", "D3DKMTQueryResourceInfo", "D3DKMTRender", "D3DKMTSetAllocationPriority", "D3DKMTSetContextSchedulingPriority", "D3DKMTSetDisplayMode", "D3DKMTSetDisplayPrivateDriverFormat", "D3DKMTSetGammaRamp", "D3DKMTSetVidPnSourceOwner", "D3DKMTSignalSynchronizationObject", "D3DKMTUnlock", "D3DKMTWaitForSynchronizationObject", "D3DKMTWaitForVerticalBlankEvent", "D3DPerformance_BeginEvent", "D3DPerformance_EndEvent", "D3DPerformance_GetStatus", "D3DPerformance_SetMarker", "EnableFeatureLevelUpgrade", "OpenAdapter10", "OpenAdapter10_2" };

extern HMODULE chain;
extern FARPROC functions[func_count];

void hook_exports();

} // namespace d3d11


#endif // SP_D3D11_DLL_DATA_MAIN_H_