/*
    CONTRIBUTORS:
        Sean Pesce

    Undocumented function prototypes were determined using IDA Pro and the following references:
        https://github.com/doitsujin/dxvk/blob/master/src/d3d11/d3d11_main.cpp
        https://github.com/bo3b/3Dmigoto/blob/master/DirectX11/D3D11Wrapper.cpp
        https://chromium.googlesource.com/external/p3/regal/+/cass/src/apitrace/wrappers/d3d11stubs.cpp
*/
#pragma once

#ifndef SP_D3D11_DLL_EXPORTS_H_
#define SP_D3D11_DLL_EXPORTS_H_

#include "main.h"


// Creates an instance of IDirect3DDevice from an IDXGIDevice.
// https://msdn.microsoft.com/en-us/library/windows/apps/dn895087.aspx
typedef HRESULT (WINAPI *CreateDirect3D11DeviceFromDXGIDevice_t)(IDXGIDevice*, IInspectable**);
HRESULT WINAPI CreateDirect3D11DeviceFromDXGIDevice_(_In_ IDXGIDevice* dxgiDevice, _Out_ IInspectable** graphicsDevice);


// Creates an instance of IDirect3DSurface from an IDXGISurface.
// https://msdn.microsoft.com/en-us/library/windows/apps/dn895088.aspx
typedef HRESULT (WINAPI *CreateDirect3D11SurfaceFromDXGISurface_t)(IDXGISurface*, IInspectable**);
HRESULT WINAPI CreateDirect3D11SurfaceFromDXGISurface_(_In_ IDXGISurface* dxgiSurface, _Out_ IInspectable** graphicsSurface);


typedef HRESULT (WINAPI *D3D11CoreCreateDevice_t)(
    IDXGIFactory*,
    IDXGIAdapter*,
    UINT,
    const D3D_FEATURE_LEVEL*,
    UINT,
    ID3D11Device**
);
HRESULT WINAPI D3D11CoreCreateDevice_(
    IDXGIFactory* pFactory,
    IDXGIAdapter* pAdapter,
    UINT Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    ID3D11Device** ppDevice
);


typedef HRESULT (WINAPI *D3D11CoreCreateLayeredDevice_t)(
    const void*,
    DWORD,
    const void*,
    REFIID,
    void**
);
HRESULT WINAPI D3D11CoreCreateLayeredDevice_(
    const void* unknown0,
    DWORD unknown1,
    const void* unknown2,
    REFIID riid,
    void** ppvObj
);


typedef SIZE_T (WINAPI *D3D11CoreGetLayeredDeviceSize_t)(const void*, DWORD);
SIZE_T WINAPI D3D11CoreGetLayeredDeviceSize_(const void* unknown0, DWORD unknown1);


typedef HRESULT (WINAPI *D3D11CoreRegisterLayers_t)(const void*, DWORD);
HRESULT WINAPI D3D11CoreRegisterLayers_(const void* unknown0, DWORD unknown1);


// Creates a device that represents the display adapter.
// https://msdn.microsoft.com/en-us/library/windows/desktop/ff476082%28v=vs.85%29.aspx?f=255&MSPPError=-2147217396
typedef HRESULT (WINAPI *D3D11CreateDevice_t)(
    _In_opt_ IDXGIAdapter*,
    D3D_DRIVER_TYPE,
    HMODULE,
    UINT,
    _In_opt_ const D3D_FEATURE_LEVEL*,
    UINT,
    UINT,
    _Out_opt_ ID3D11Device**,
    _Out_opt_ D3D_FEATURE_LEVEL*,
    _Out_opt_ ID3D11DeviceContext**
);
HRESULT WINAPI D3D11CreateDevice_(
    _In_opt_ IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    _In_opt_ const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    _Out_opt_ ID3D11Device** ppDevice,
    _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    _Out_opt_ ID3D11DeviceContext** ppImmediateContext
);


// Creates a device that represents the display adapter and a swap chain used for rendering.
// https://msdn.microsoft.com/en-us/library/windows/desktop/ff476083(v=vs.85).aspx
typedef HRESULT (WINAPI *D3D11CreateDeviceAndSwapChain_t)(
    _In_opt_ IDXGIAdapter*,
    D3D_DRIVER_TYPE,
    HMODULE,
    UINT,
    _In_opt_ const D3D_FEATURE_LEVEL*,
    UINT,
    UINT,
    _In_opt_ const DXGI_SWAP_CHAIN_DESC*,
    _Out_opt_ IDXGISwapChain**,
    _Out_opt_ ID3D11Device**,
    _Out_opt_ D3D_FEATURE_LEVEL*,
    _Out_opt_ ID3D11DeviceContext**
);
HRESULT WINAPI D3D11CreateDeviceAndSwapChain_(
    _In_opt_ IDXGIAdapter* pAdapter,
    D3D_DRIVER_TYPE DriverType,
    HMODULE Software,
    UINT Flags,
    _In_opt_ const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT SDKVersion,
    _In_opt_ const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
    _Out_opt_ IDXGISwapChain** ppSwapChain,
    _Out_opt_ ID3D11Device** ppDevice,
    _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    _Out_opt_ ID3D11DeviceContext** ppImmediateContext
);


typedef HRESULT (WINAPI *D3D11CreateDeviceForD3D12_t)(
    IUnknown*,
    UINT,
    const D3D_FEATURE_LEVEL*,
    UINT,
    UINT,
    UINT,
    ID3D11Device**,
    ID3D11DeviceContext**,
    D3D_FEATURE_LEVEL*
);
HRESULT WINAPI D3D11CreateDeviceForD3D12_(
    IUnknown* pDevice,
    UINT Flags,
    const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    UINT NumQueues, // ? SDKVersion ?
    UINT NodeMask, // ? NumQueues ?
    ID3D11Device** ppDevice,
    ID3D11DeviceContext** ppImmediateContext,
    D3D_FEATURE_LEVEL* pChosenFeatureLevel
);


typedef HRESULT (WINAPI *D3D11On12CreateDevice_t)(
    _In_ IUnknown*,
    UINT,
    _In_opt_ const D3D_FEATURE_LEVEL*,
    UINT,
    _In_opt_ IUnknown*,
    UINT,
    UINT,
    _Out_opt_ ID3D11Device**,
    _Out_opt_ ID3D11DeviceContext**,
    _Out_opt_ D3D_FEATURE_LEVEL*
);
HRESULT WINAPI D3D11On12CreateDevice_(
    _In_ IUnknown* pDevice,
    UINT Flags,
    _In_opt_ const D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels,
    _In_opt_ IUnknown* ppCommandQueues,
    UINT NumQueues,
    UINT NodeMask,
    _Out_opt_ ID3D11Device** ppDevice,
    _Out_opt_ ID3D11DeviceContext** ppImmediateContext,
    _Out_opt_ D3D_FEATURE_LEVEL* pChosenFeatureLevel
);


// Closes a graphics adapter that was previously opened by using the D3DKMTOpenAdapterFromHdc function.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtcloseadapter
//NTSTATUS APIENTRY D3DKMTCloseAdapter(const D3DKMT_CLOSEADAPTER* pAdapter);
typedef HRESULT (WINAPI *D3DKMTCloseAdapter_t)();
HRESULT WINAPI D3DKMTCloseAdapter_();


// Creates allocations of system or video memory.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation
//NTSTATUS APIENTRY D3DKMTCreateAllocation(D3DKMT_CREATEALLOCATION* Arg1);
typedef HRESULT (WINAPI *D3DKMTCreateAllocation_t)();
HRESULT WINAPI D3DKMTCreateAllocation_();


// Creates a kernel-mode device context.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontext
//NTSTATUS APIENTRY D3DKMTCreateContext(D3DKMT_CREATECONTEXT* Arg1);
typedef HRESULT (WINAPI *D3DKMTCreateContext_t)();
HRESULT WINAPI D3DKMTCreateContext_();


// Creates a kernel-mode device context.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice
//NTSTATUS APIENTRY D3DKMTCreateDevice(D3DKMT_CREATEDEVICE* Arg1);
typedef HRESULT (WINAPI *D3DKMTCreateDevice_t)();
HRESULT WINAPI D3DKMTCreateDevice_();


// Creates a kernel-mode synchronization object.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject
//NTSTATUS APIENTRY D3DKMTCreateSynchronizationObject(D3DKMT_CREATESYNCHRONIZATIONOBJECT* Arg1);
typedef HRESULT (WINAPI *D3DKMTCreateSynchronizationObject_t)();
HRESULT WINAPI D3DKMTCreateSynchronizationObject_();


// Releases a resource, a list of allocations, or both.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtdestroyallocation
//NTSTATUS APIENTRY D3DKMTDestroyAllocation(const D3DKMT_DESTROYALLOCATION* Arg1);
typedef HRESULT (WINAPI *D3DKMTDestroyAllocation_t)();
HRESULT WINAPI D3DKMTDestroyAllocation_();


// Releases a kernel-mode device context.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtdestroycontext
//NTSTATUS APIENTRY D3DKMTDestroyContext(const D3DKMT_DESTROYCONTEXT* Arg1);
typedef HRESULT (WINAPI *D3DKMTDestroyContext_t)();
HRESULT WINAPI D3DKMTDestroyContext_();


// Releases a kernel-mode device context.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtdestroydevice
//NTSTATUS APIENTRY D3DKMTDestroyDevice(const D3DKMT_DESTROYDEVICE* Arg1);
typedef HRESULT (WINAPI *D3DKMTDestroyDevice_t)();
HRESULT WINAPI D3DKMTDestroyDevice_();


// Destroys a kernel-mode synchronization object.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtdestroysynchronizationobject
//NTSTATUS APIENTRY D3DKMTDestroySynchronizationObject(const D3DKMT_DESTROYSYNCHRONIZATIONOBJECT* Arg1);
typedef HRESULT (WINAPI *D3DKMTDestroySynchronizationObject_t)();
HRESULT WINAPI D3DKMTDestroySynchronizationObject_();


// Exchanges information with the display miniport driver.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtescape
//NTSTATUS APIENTRY D3DKMTEscape(const D3DKMT_ESCAPE* Arg1);
typedef HRESULT (WINAPI *D3DKMTEscape_t)();
HRESULT WINAPI D3DKMTEscape_();


// Retrieves the scheduling priority for a device context.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtgetcontextschedulingpriority
//NTSTATUS APIENTRY D3DKMTGetContextSchedulingPriority(D3DKMT_GETCONTEXTSCHEDULINGPRIORITY* Arg1);
typedef HRESULT (WINAPI *D3DKMTGetContextSchedulingPriority_t)();
HRESULT WINAPI D3DKMTGetContextSchedulingPriority_();


// Retrieves the state of a device.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate
//NTSTATUS APIENTRY D3DKMTGetDeviceState(D3DKMT_GETDEVICESTATE* Arg1);
typedef HRESULT (WINAPI *D3DKMTGetDeviceState_t)();
HRESULT WINAPI D3DKMTGetDeviceState_();


// Retrieves a list of available display modes, including modes with extended format.
// https://msdn.microsoft.com/en-us/windows/hardware/ff546967(v=vs.100)
//NTSTATUS APIENTRY D3DKMTGetDisplayModeList(_Inout_ D3DKMT_GETDISPLAYMODELIST* pData);
typedef HRESULT (WINAPI *D3DKMTGetDisplayModeList_t)();
HRESULT WINAPI D3DKMTGetDisplayModeList_();


// Retrieves a list of multiple-sample methods that are used for an allocation.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtgetmultisamplemethodlist
//NTSTATUS APIENTRY D3DKMTGetMultisampleMethodList(D3DKMT_GETMULTISAMPLEMETHODLIST* Arg1);
typedef HRESULT (WINAPI *D3DKMTGetMultisampleMethodList_t)();
HRESULT WINAPI D3DKMTGetMultisampleMethodList_();


// For system use only.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtgetruntimedata
//NTSTATUS APIENTRY D3DKMTGetRuntimeData(const D3DKMT_GETRUNTIMEDATA* Arg1);
typedef HRESULT (WINAPI *D3DKMTGetRuntimeData_t)();
HRESULT WINAPI D3DKMTGetRuntimeData_();


// Retrieves the global shared handle for the primary surface.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtgetsharedprimaryhandle
//NTSTATUS APIENTRY D3DKMTGetSharedPrimaryHandle(D3DKMT_GETSHAREDPRIMARYHANDLE* Arg1);
typedef HRESULT (WINAPI *D3DKMTGetSharedPrimaryHandle_t)();
HRESULT WINAPI D3DKMTGetSharedPrimaryHandle_();


// Locks an entire allocation or specific pages within an allocation.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtlock
//NTSTATUS APIENTRY D3DKMTLock(D3DKMT_LOCK* Arg1);
typedef HRESULT (WINAPI *D3DKMTLock_t)();
HRESULT WINAPI D3DKMTLock_();


// Maps a device context handle (HDC) to a graphics adapter handle and, if the adapter contains multiple monitor outputs, to one of those outputs.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromhdc
//NTSTATUS APIENTRY D3DKMTOpenAdapterFromHdc(D3DKMT_OPENADAPTERFROMHDC* Arg1);
typedef HRESULT (WINAPI *D3DKMTOpenAdapterFromHdc_t)();
HRESULT WINAPI D3DKMTOpenAdapterFromHdc_();


// Opens a shared resource.
// https://technet.microsoft.com/en-us/windows/ff547065%28v=vs.80%29?f=255&MSPPError=-2147217396
//NTSTATUS APIENTRY D3DKMTOpenResource(_Inout_ D3DKMT_OPENRESOURCE* pData);
typedef HRESULT (WINAPI *D3DKMTOpenResource_t)();
HRESULT WINAPI D3DKMTOpenResource_();


// Submits a present command to the Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys).
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtpresent
//NTSTATUS APIENTRY D3DKMTPresent(D3DKMT_PRESENT* Arg1);
typedef HRESULT (WINAPI *D3DKMTPresent_t)();
HRESULT WINAPI D3DKMTPresent_();


// Retrieves graphics adapter information.
// https://msdn.microsoft.com/en-us/windows/ff547100(v=vs.80)
//NTSTATUS APIENTRY D3DKMTQueryAdapterInfo(_Inout_ const D3DKMT_QUERYADAPTERINFO* pData);
typedef HRESULT (WINAPI *D3DKMTQueryAdapterInfo_t)();
HRESULT WINAPI D3DKMTQueryAdapterInfo_();


// Retrieves the residency status of a resource or list of allocations.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtqueryallocationresidency
//NTSTATUS APIENTRY D3DKMTQueryAllocationResidency(const D3DKMT_QUERYALLOCATIONRESIDENCY* Arg1);
typedef HRESULT (WINAPI *D3DKMTQueryAllocationResidency_t)();
HRESULT WINAPI D3DKMTQueryAllocationResidency_();


// Retrieves information about a shared resource.
// https://technet.microsoft.com/en-us/windows/ff547124(v=vs.60)
//NTSTATUS APIENTRY D3DKMTQueryResourceInfo(_Inout_ D3DKMT_QUERYRESOURCEINFO* pData);
typedef HRESULT (WINAPI *D3DKMTQueryResourceInfo_t)();
HRESULT WINAPI D3DKMTQueryResourceInfo_();


// Submits the current command buffer to the Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys).
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtrender
//NTSTATUS APIENTRY D3DKMTRender(D3DKMT_RENDER* Arg1);
typedef HRESULT (WINAPI *D3DKMTRender_t)();
HRESULT WINAPI D3DKMTRender_();


// Sets the priority level of a resource or list of allocations.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsetallocationpriority
//NTSTATUS APIENTRY D3DKMTSetAllocationPriority(const D3DKMT_SETALLOCATIONPRIORITY* Arg1);
typedef HRESULT (WINAPI *D3DKMTSetAllocationPriority_t)();
HRESULT WINAPI D3DKMTSetAllocationPriority_();


// Sets the scheduling priority for a device context.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsetcontextschedulingpriority
//NTSTATUS APIENTRY D3DKMTSetContextSchedulingPriority(const D3DKMT_SETCONTEXTSCHEDULINGPRIORITY* Arg1);
typedef HRESULT (WINAPI *D3DKMTSetContextSchedulingPriority_t)();
HRESULT WINAPI D3DKMTSetContextSchedulingPriority_();


// Sets the allocation that is used to scan out to the display.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode
//NTSTATUS APIENTRY D3DKMTSetDisplayMode(const D3DKMT_SETDISPLAYMODE* Arg1);
typedef HRESULT (WINAPI *D3DKMTSetDisplayMode_t)();
HRESULT WINAPI D3DKMTSetDisplayMode_();


// Changes the private-format attribute of a video present source.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplayprivatedriverformat
//NTSTATUS APIENTRY D3DKMTSetDisplayPrivateDriverFormat(const D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT* Arg1);
typedef HRESULT (WINAPI *D3DKMTSetDisplayPrivateDriverFormat_t)();
HRESULT WINAPI D3DKMTSetDisplayPrivateDriverFormat_();


// Sets the gamma ramp.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsetgammaramp
//NTSTATUS APIENTRY D3DKMTSetGammaRamp(const D3DKMT_SETGAMMARAMP* Arg1);
typedef HRESULT (WINAPI *D3DKMTSetGammaRamp_t)();
HRESULT WINAPI D3DKMTSetGammaRamp_();


// Sets and releases the video present source in the path of a video present network (VidPN) topology that owns the VidPN.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsetvidpnsourceowner
//NTSTATUS APIENTRY D3DKMTSetVidPnSourceOwner(const D3DKMT_SETVIDPNSOURCEOWNER* Arg1);
typedef HRESULT (WINAPI *D3DKMTSetVidPnSourceOwner_t)();
HRESULT WINAPI D3DKMTSetVidPnSourceOwner_();


// Inserts a signal for the specified synchronization objects in the specified context stream.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtsignalsynchronizationobject
//NTSTATUS APIENTRY D3DKMTSignalSynchronizationObject(const D3DKMT_SIGNALSYNCHRONIZATIONOBJECT* Arg1);
typedef HRESULT (WINAPI *D3DKMTSignalSynchronizationObject_t)();
HRESULT WINAPI D3DKMTSignalSynchronizationObject_();


// Unlocks a list of allocations.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtunlock
//NTSTATUS APIENTRY D3DKMTUnlock(const D3DKMT_UNLOCK* Arg1);
typedef HRESULT (WINAPI *D3DKMTUnlock_t)();
HRESULT WINAPI D3DKMTUnlock_();


// Inserts a wait for the specified synchronization objects in the specified context stream.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforsynchronizationobject
//NTSTATUS APIENTRY D3DKMTWaitForSynchronizationObject(const D3DKMT_WAITFORSYNCHRONIZATIONOBJECT* Arg1);
typedef HRESULT (WINAPI *D3DKMTWaitForSynchronizationObject_t)();
HRESULT WINAPI D3DKMTWaitForSynchronizationObject_();


// Waits for the vertical blanking interval to occur and then returns.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforverticalblankevent
//NTSTATUS APIENTRY D3DKMTWaitForVerticalBlankEvent(const D3DKMT_WAITFORVERTICALBLANKEVENT* Arg1);
typedef HRESULT (WINAPI *D3DKMTWaitForVerticalBlankEvent_t)();
HRESULT WINAPI D3DKMTWaitForVerticalBlankEvent_();



//////////////////// UNDOCUMENTED FUNCTIONS ////////////////////
typedef void* (*D3DPerformance_BeginEvent_t)(void*, void*);
void* D3DPerformance_BeginEvent_(void* unknown0, void* unknown1); // ? D3DPerformance_BeginEvent_(void* unknown0) ?

typedef void* (*D3DPerformance_EndEvent_t)(void**);
void* D3DPerformance_EndEvent_(void** unknown0);

typedef void* (*D3DPerformance_GetStatus_t)(void**);
void* D3DPerformance_GetStatus_(void** unknown0);

typedef UINT (*D3DPerformance_SetMarker_t)(void*, void*);
UINT D3DPerformance_SetMarker_(void* unknown0, void* unknown1);

typedef void* (WINAPI *EnableFeatureLevelUpgrade_t)();
void* WINAPI EnableFeatureLevelUpgrade_();
////////////////////////////////////////////////////////////////


// Creates a graphics adapter object that is referenced in subsequent calls.
// https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/content/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter
//HRESULT APIENTRY OpenAdapter10(D3D10DDIARG_OPENADAPTER* pOpenData);
typedef HRESULT (WINAPI *OpenAdapter10_t)(void*);
HRESULT WINAPI OpenAdapter10_(void* pOpenData);


// Creates a graphics adapter object that is referenced in subsequent calls.
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff568603%28v=vs.85%29.aspx
//HRESULT APIENTRY OpenAdapter10_2(_Inout_ D3D10DDIARG_OPENADAPTER* pOpenData);
typedef HRESULT (WINAPI *OpenAdapter10_2_t)(void*);
HRESULT WINAPI OpenAdapter10_2_(_Inout_ void* pOpenData);



#endif // SP_D3D11_DLL_EXPORTS_H_