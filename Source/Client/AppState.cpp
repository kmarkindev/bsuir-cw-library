#include "AppState.h"

AppState AppState::_instance;

AppState& AppState::GetAppState() noexcept
{
    return _instance;
}

void AppState::SetConfig(AppConfig config)
{
    _config = std::move(config);
}

AppConfig AppState::GetConfig()
{
    return _config;
}

void AppState::SetAuthorization(std::string_view token)
{
    _token = token;
    _onLoginEvent.Notify();
}

void AppState::ResetAuthorization()
{
    _token = std::nullopt;
    _onLogoutEvent.Notify();
}

bool AppState::IsAuthorized()
{
    return _token.has_value();
}

Event<>& AppState::GetLoginEvent()
{
    return _onLoginEvent;
}

Event<>& AppState::GetLogoutEvent()
{
    return _onLogoutEvent;
}

Event<ApiErrorException>& AppState::GetApiErrorEvent()
{
    return _onApiErrorEvent;
}