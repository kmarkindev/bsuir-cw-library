#pragma once

#include <Dto/AppConfig.h>
#include <string>
#include <optional>
#include <Utils/Event.h>
#include <Exceptions/ApiErrorException.h>

class AppState
{
public:
    static AppState& GetAppState() noexcept;

    void SetConfig(AppConfig config);
    AppConfig GetConfig();

    bool IsAuthorized();
    void SetAuthorization(std::string_view token);
    void ResetAuthorization();
    std::string GetAuthorizationToken();

    Event<>& GetLoginEvent();
    Event<>& GetLogoutEvent();
    Event<ApiErrorException>& GetApiErrorEvent();

private:
    static AppState _instance;
    AppState() noexcept = default;
    AppState& operator=(const AppState&) noexcept = default;
    AppState& operator=(AppState&&) noexcept = default;

    AppConfig _config;
    std::optional<std::string> _token;
    Event<> _onLoginEvent;
    Event<> _onLogoutEvent;
    Event<ApiErrorException> _onApiErrorEvent;
};
