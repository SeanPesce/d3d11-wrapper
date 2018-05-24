/*
    CONTRIBUTORS:
        Sean Pesce

*/
#pragma once

#ifndef SP_DLL_H_
#define SP_DLL_H_


#include "d3d11/main.h"
#include "sp/main.h"
#include "sp/main/preferences.h"
#include "sp/log.h"


namespace events {



inline BOOL on_process_attach(HMODULE h_module, LPVOID lp_reserved)
{
    if constexpr (SP_DEBUG_BUILD)
    {
        global::cmd_out << "\n\n          +---------------------+\n          |  D3D11.DLL WRAPPER  |\n          |     DEBUG BUILD     |\n          +---------------------+\n\n\n";
    }

    prefs::initialize("d3d11_mod.ini");

    SP_LOG("\n[%s %s] Attached to process.\n",
        sp::str::get_date(sp::util::YYYYMMDD).c_str(),
        sp::str::get_time().c_str());

    d3d11::hook_exports();

    return TRUE;
}


inline BOOL on_process_detach(HMODULE h_module, LPVOID lp_reserved)
{
    SP_LOG("[%s %s] Detached from process.\n",
        sp::str::get_date(sp::util::YYYYMMDD).c_str(),
        sp::str::get_time().c_str());

    return BOOL(!!FreeLibrary(d3d11::chain));
}


inline BOOL on_thread_attach(HMODULE h_module, LPVOID lp_reserved)
{
    return TRUE;
}


inline BOOL on_thread_detach(HMODULE h_module, LPVOID lp_reserved)
{
    return TRUE;
}


} // namespace events


#endif // SP_DLL_H_
