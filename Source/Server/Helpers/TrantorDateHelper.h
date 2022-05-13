#pragma once

#include <drogon/drogon.h>
#include <string>

inline trantor::Date TrantorDateFromString(const std::string& str)
{
    struct tm stm;
    memset(&stm,0,sizeof(stm));
    strptime(str.c_str(),"%Y-%m-%d",&stm);
    time_t t = mktime(&stm);
    return trantor::Date(t*1000000);
}