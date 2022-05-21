#pragma once

#include <string>
#include <optional>
#include <stdexcept>
#include <Services/HttpClient/HttpClient.h>
#include <vector>
#include <Exceptions/ApiErrorException.h>
#include <Dto/AppConfig.h>

template<typename ModelType>
class Repository
{
public:

    explicit Repository(AppConfig config)
        : _config(std::move(config))
    {

    }

    void SetToken(std::string token)
    {
        _token = std::move(token);
    }

    std::string GetToken()
    {
        if(!_token.has_value())
            throw std::runtime_error("Token is null");
        return _token.value();
    }

    void EraseToken()
    {
        _token = std::nullopt;
    }

    bool HasToken()
    {
        return _token.has_value();
    }

    virtual ModelType GetById(std::uint64_t id)
    {
        auto response = FetchApi("GET", _config.apiUrl, std::string(ModelType::GetPath()) + "/" + std::to_string(id));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json);
    }

    virtual std::vector<ModelType> GetAll()
    {
        auto response = FetchApi("GET", _config.apiUrl, std::string(ModelType::GetPath()));
        auto json = nlohmann::json::parse(response.GetBody());

        std::vector<ModelType> models;
        for(const auto& item : json["data"])
            models.emplace_back(item);
        return models;
    }

    virtual ModelType Create(const ModelType& model)
    {
        auto response = FetchApi("POST", _config.apiUrl, std::string(ModelType::GetPath()), to_string(model.ToJson()));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json);
    }

    virtual ModelType Update(const ModelType& model)
    {
        auto body = model.ToJson();
        if(!body["id"].empty())
            body["id"].clear();

        auto response = FetchApi("PUT", _config.apiUrl, std::string(ModelType::GetPath()), to_string(body));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json);
    }

    virtual ModelType Delete(std::uint64_t id)
    {
        auto response = FetchApi("DELETE", _config.apiUrl, std::string(ModelType::GetPath()) + "/" + std::to_string(id));
        auto json = nlohmann::json::parse(response.GetBody());

        return ModelType(json);
    }

protected:

    HttpResponse FetchApi(std::string_view method, std::string_view host, std::string_view path, std::string_view body = {})
    {
        HttpRequest request(method, host, path);
        AppendTokenHeaderIfPossible(request);

        auto response = HttpClient::Send(request);
        response.SetBody(body);

        if(response.GetCode() != 200)
            throw ApiErrorException(nlohmann::json::parse(response.GetBody()));

        return response;
    }

    void AppendTokenHeaderIfPossible(HttpRequest& request)
    {
        if(HasToken())
            request.GetHeaders().SetHeader({"jwt-token", GetToken()});
    }

private:
    AppConfig _config;
    std::optional<std::string> _token;
};
