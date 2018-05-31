/*
    CONTRIBUTORS:
        Sean Pesce

*/
#pragma once

#ifndef SP_DLL_LIFECYCLE_EVENTS_H_
#define SP_DLL_LIFECYCLE_EVENTS_H_


#include "d3d11/main.h"
#include "sp/main.h"
#include "sp/main/preferences.h"
#include "sp/log.h"


#ifndef D3D11_ON_PROCESS_ATTACH
#define D3D11_ON_PROCESS_ATTACH(h_module, lp_reserved)
#endif // D3D11_ON_PROCESS_ATTACH
#ifndef D3D11_ON_PROCESS_DETACH
#define D3D11_ON_PROCESS_DETACH(h_module, lp_reserved)
#endif // D3D11_ON_PROCESS_DETACH
#ifndef D3D11_ON_THREAD_ATTACH
#define D3D11_ON_THREAD_ATTACH(h_module, lp_reserved)
#endif // D3D11_ON_THREAD_ATTACH
#ifndef D3D11_ON_THREAD_DETACH
#define D3D11_ON_THREAD_DETACH(h_module, lp_reserved)
#endif // D3D11_ON_THREAD_DETACH



namespace dll {

typedef BOOL(*entry_point_t)(HMODULE, LPVOID);

constexpr const char* build = __DATE__ "   " __TIME__;


inline BOOL on_process_attach(HMODULE h_module, LPVOID lp_reserved)
{
    prefs::initialize("d3d11_mod.ini");

    if constexpr (SP_DEBUG_BUILD)
    {
        global::cmd_out
            << "\n\n          +---------------------+\n          |  D3D11.DLL WRAPPER  |\n          |     DEBUG BUILD     |\n          +---------------------+\nCompiled: "
            << dll::build << "\nUtils library compiled: " << sp::build << "\n\n\n";
    }

    SP_LOG("[%s %s] Attached to process.\n",
        sp::str::get_date(sp::util::YYYYMMDD).c_str(),
        sp::str::get_time().c_str());

    d3d11::hook_exports();

    D3D11_ON_PROCESS_ATTACH(h_module, lp_reserved);

    return TRUE;
}


inline BOOL on_process_detach(HMODULE h_module, LPVOID lp_reserved)
{
    D3D11_ON_PROCESS_DETACH(h_module, lp_reserved);

    SP_LOG("[%s %s] Detached from process.\n\n",
        sp::str::get_date(sp::util::YYYYMMDD).c_str(),
        sp::str::get_time().c_str());

    return BOOL(!!FreeLibrary(d3d11::chain));
}


inline BOOL on_thread_attach(HMODULE h_module, LPVOID lp_reserved)
{
    D3D11_ON_THREAD_ATTACH(h_module, lp_reserved);
    return TRUE;
}


inline BOOL on_thread_detach(HMODULE h_module, LPVOID lp_reserved)
{
    D3D11_ON_THREAD_DETACH(h_module, lp_reserved);
    return TRUE;
}


} // namespace dll


#endif // SP_DLL_LIFECYCLE_EVENTS_H_
