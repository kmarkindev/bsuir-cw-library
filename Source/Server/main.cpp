#include <drogon/drogon.h>
#include <filesystem>
#include <fstream>

Json::Value loadConfigFile()
{
    Json::Value config;

    auto path = std::filesystem::path("./configs/config.json");
    std::ifstream fs(path);
    fs >> config;

    return config;
}

int main() {
    drogon::app()
        .loadConfigJson(loadConfigFile())
        .run();
}