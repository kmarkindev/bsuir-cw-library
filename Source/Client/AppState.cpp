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
}

void AppState::ResetAuthorization()
{
    _token = std::nullopt;
}

bool AppState::IsAuthorized()
{
    return _token.has_value();
}
