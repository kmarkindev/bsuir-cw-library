#pragma once

#include <string>
#include <chrono>

inline std::chrono::time_point<std::chrono::system_clock> ParseTime(const std::string& str)
{
    std::tm tm = {};
    std::stringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

inline std::string RenderTimeString(std::chrono::time_point<std::chrono::system_clock> time)
{
    std::time_t t = std::chrono::system_clock::to_time_t(time);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%Y-%m-%d");
    return ss.str();
}