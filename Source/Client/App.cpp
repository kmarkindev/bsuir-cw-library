#include "App.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <AppState.h>
#include <Windows/MainWindow.h>

bool App::OnInit()
{
    auto& appState = AppState::GetAppState();
    AppConfig config;
    config.apiUrl = "http://lib.kmarkin.com";

    std::fstream stream("override.json");
    if(stream.is_open())
    {
        std::string content(std::istreambuf_iterator<char>(stream), {});
        auto json = nlohmann::json::parse(content);
        config.apiUrl = json["api_url"];

        std::string token = json["token"];
        appState.SetAuthorization(token);
    }

    appState.SetConfig(config);

    auto window = new MainWindow();
    window->Show();

    return true;
}