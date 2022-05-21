#include "App.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <AppState.h>
#include <Windows/WelcomeWindow.h>

bool App::OnInit()
{
    AppConfig config;
    config.apiUrl = "http://lib.kmarkin.com/";

    std::fstream stream("override.json");
    if(stream.is_open())
    {
        std::string content(std::istreambuf_iterator<char>(stream), {});
        auto json = nlohmann::json::parse(content);
        config.apiUrl = json["api_url"];
    }

    AppState::GetAppState().SetConfig(config);

    auto window = new WelcomeWindow();
    window->Show();

    return true;
}