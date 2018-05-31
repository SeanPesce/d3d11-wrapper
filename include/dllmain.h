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


namespace dll {
typedef BOOL(entry_point_t)(HMODULE, LPVOID);
}

#ifdef WRAPPER_ON_PROCESS_ATTACH
extern dll::entry_point_t WRAPPER_ON_PROCESS_ATTACH;
#define WRAPPER_ON_PROCESS_ATTACH_GLOBAL_NS :: ## WRAPPER_ON_PROCESS_ATTACH
#else
#define WRAPPER_ON_PROCESS_ATTACH_GLOBAL_NS(h_module, lp_reserved)
#endif // WRAPPER_ON_PROCESS_ATTACH

#ifdef WRAPPER_ON_PROCESS_DETACH
extern dll::entry_point_t WRAPPER_ON_PROCESS_DETACH;
#define WRAPPER_ON_PROCESS_DETACH_GLOBAL_NS :: ## WRAPPER_ON_PROCESS_DETACH
#else
#define WRAPPER_ON_PROCESS_DETACH_GLOBAL_NS(h_module, lp_reserved)
#endif // WRAPPER_ON_PROCESS_DETACH

#ifdef WRAPPER_ON_THREAD_ATTACH
extern dll::entry_point_t WRAPPER_ON_THREAD_ATTACH;
#define WRAPPER_ON_THREAD_ATTACH_GLOBAL_NS :: ## WRAPPER_ON_THREAD_ATTACH
#else
#define WRAPPER_ON_THREAD_ATTACH_GLOBAL_NS(h_module, lp_reserved)
#endif // WRAPPER_ON_THREAD_ATTACH

#ifdef WRAPPER_ON_THREAD_DETACH
extern dll::entry_point_t WRAPPER_ON_THREAD_DETACH;
#define WRAPPER_ON_THREAD_DETACH_GLOBAL_NS :: ## WRAPPER_ON_THREAD_DETACH
#else
#define WRAPPER_ON_THREAD_DETACH_GLOBAL_NS(h_module, lp_reserved)
#endif // WRAPPER_ON_THREAD_DETACH



namespace dll {

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

    WRAPPER_ON_PROCESS_ATTACH_GLOBAL_NS(h_module, lp_reserved);

    return TRUE;
}


inline BOOL on_process_detach(HMODULE h_module, LPVOID lp_reserved)
{
    WRAPPER_ON_PROCESS_DETACH_GLOBAL_NS(h_module, lp_reserved);

    SP_LOG("[%s %s] Detached from process.\n\n",
        sp::str::get_date(sp::util::YYYYMMDD).c_str(),
        sp::str::get_time().c_str());

    return BOOL(!!FreeLibrary(d3d11::chain));
}


inline BOOL on_thread_attach(HMODULE h_module, LPVOID lp_reserved)
{
    WRAPPER_ON_THREAD_ATTACH_GLOBAL_NS(h_module, lp_reserved);
    return TRUE;
}


inline BOOL on_thread_detach(HMODULE h_module, LPVOID lp_reserved)
{
    WRAPPER_ON_THREAD_DETACH_GLOBAL_NS(h_module, lp_reserved);
    return TRUE;
}


} // namespace dll


#endif // SP_DLL_LIFECYCLE_EVENTS_H_
