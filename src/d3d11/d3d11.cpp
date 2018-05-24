/*
    CONTRIBUTORS:
        Sean Pesce

*/

#include "d3d11/main.h"

namespace d3d11 {

void* chain;
void* functions[func_count];

void hook_exports()
{
    char path[MAX_PATH];
    if (!GetSystemDirectory(path, MAX_PATH))
    {
        // @TODO: Handle error
    }
    strcat_s(path, "\\");
    strcat_s(path, filename);
    chain = LoadLibrary(path);
    for (int i = 0; i < d3d11::func_count; i++)
    {
        functions[i] = GetProcAddress((HMODULE)chain, func_names[i]);
    }
}

} // namespace d3d11



