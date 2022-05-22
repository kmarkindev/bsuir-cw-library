#pragma once

#include <functional>
#include <map>

template<typename... CallbackArgs>
class Event
{
public:

    using CallbackSignature = void(CallbackArgs...);

    std::uint32_t Subscribe(std::function<CallbackSignature> callback)
    {
        _lastId += 1;
        _callbacks[_lastId] = std::move(callback);
        return _lastId;
    }

    void Unsubscribe(std::uint32_t callbackId)
    {
        _callbacks.erase(callbackId);
    }

    void Notify(const CallbackArgs&... args)
    {
        for(auto& callback : _callbacks)
            callback.second(args...);
    }

private:
    std::uint32_t _lastId = 0;
    std::map<std::uint32_t, std::function<CallbackSignature>> _callbacks;
};
