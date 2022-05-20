#pragma once

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include "HttpResponse.h"
#include "HttpRequest.h"

class HttpClient
{
public:
    HttpResponse Send(const HttpRequest& request);
};
