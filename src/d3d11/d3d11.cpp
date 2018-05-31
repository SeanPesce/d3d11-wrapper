/*
    CONTRIBUTORS:
        Sean Pesce

*/

#include "d3d11/main.h"
#include "sp/environment.h"
#include "sp/main/preferences.h"


namespace d3d11 {

HMODULE chain = NULL;
FARPROC functions[func_count];

void hook_exports()
{
    std::string path(user_setting<std::string>("DLL", "d3d11Chain", "").read());
    if (!path.empty())
    {
        SP_LOG("Attempting to chain d3d11 wrapper (%s)... ", path.c_str());
        chain = LoadLibrary(path.c_str());
        SP_LOG(chain ? "Success\n" : "Failed.\n");
    }
    if (!chain)
    {
        SP_LOG("Attempting to load %s from system path... ", filename);
        path = sp::env::system_dir() + "\\" + filename;
        chain = LoadLibrary(path.c_str());
        SP_LOG(chain ? "Success\n" : "Failed.\nERROR: Failed to load %s\nExiting...\n", filename);
    }
    if (!chain)
    {
        MessageBox(NULL, "Unable to locate original d3d11.dll (or compatible library to chain)", "ERROR: Failed to load original d3d11.dll", NULL);
        exit(0);
    }
    
    SP_LOG("Locating exports... ");
    int count = 0;
    for (int i = 0; i < d3d11::func_count; i++)
    {
        FARPROC func = GetProcAddress(chain, func_names[i]);
        if (func)
        {
            count++;
        }
        functions[i] = func;
    }
    SP_LOG("Found %d out of %d.\n", count, d3d11::func_count);
}

} // namespace d3d11



