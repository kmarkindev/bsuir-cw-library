#pragma once

#include <Dto/AppConfig.h>
#include <string>
#include <optional>

class AppState
{
public:

    static AppState& GetAppState() noexcept;

    void SetConfig(AppConfig config);
    AppConfig GetConfig();

    bool IsAuthorized();
    void SetAuthorization(std::string_view token);
    void ResetAuthorization();
private:
    static AppState _instance;
    AppState() noexcept = default;
    AppState& operator=(const AppState&) = default;

    AppConfig _config;
    std::optional<std::string> _token;
};
