#pragma once

#include <string>
#include <optional>
#include <stdexcept>
#include <Services/HttpClient/HttpClient.h>
#include <vector>
#include <Exceptions/ApiErrorException.h>
#include <AppState.h>
#include <Dto/AppConfig.h>

template<typename ModelType>
class Repository
{
public:

    explicit Repository()
        : _config(AppState::GetAppState().GetConfig())
    {
    }

    virtual ModelType GetById(std::uint64_t id)
    {
        auto response = FetchApi("GET", _config.apiUrl, ModelType::GetPath() + "/" + std::to_string(id));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json["data"]);
    }

    virtual std::vector<ModelType> GetAll()
    {
        auto response = FetchApi("GET", _config.apiUrl, ModelType::GetPath());
        auto json = nlohmann::json::parse(response.GetBody());

        std::vector<ModelType> models;
        for(const auto& item : json["data"])
            models.emplace_back(item);
        return models;
    }

    virtual ModelType Create(const ModelType& model)
    {
        auto response = FetchApi("POST", _config.apiUrl, ModelType::GetPath(), to_string(model.ToJson()));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json["data"]);
    }

    virtual ModelType Update(const ModelType& model)
    {
        if(!model.id.has_value())
            throw std::invalid_argument("Can't update entity without id");

        auto body = model.ToJson();
        body.erase("id");

        auto response = FetchApi("PUT", _config.apiUrl,
            ModelType::GetPath() + "/" + std::to_string(model.id.value()), to_string(body));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json["data"]);
    }

    virtual ModelType Delete(std::uint64_t id)
    {
        auto response = FetchApi("DELETE", _config.apiUrl, ModelType::GetPath() + "/" + std::to_string(id));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json["data"]);
    }

protected:
    AppConfig _config;

    HttpResponse FetchApi(std::string_view method, std::string_view host, std::string_view path, std::string_view body = {})
    {
        HttpRequest request(method, host, path);
        request.GetHeaders().SetHeader({"Content-Type", "application/json"});
        request.SetBody(body);
        AppendTokenHeaderIfPossible(request);

        auto response = HttpClient::Send(request);

        if(response.GetCode() != 200)
            throw ApiErrorException(nlohmann::json::parse(response.GetBody()));

        return response;
    }

    void AppendTokenHeaderIfPossible(HttpRequest& request)
    {
        auto& appState = AppState::GetAppState();
        std::string token;

        if(appState.IsAuthorized())
            token = appState.GetAuthorizationToken();

        request.GetHeaders().SetHeader({"jwt-token", token});
    }

private:
    std::optional<std::string> _token;
};
