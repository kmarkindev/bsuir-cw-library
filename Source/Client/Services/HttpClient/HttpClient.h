#pragma once

#include <httplib.h>
#include "HttpResponse.h"
#include "HttpRequest.h"

class HttpClient
{
public:
    static HttpResponse Send(const HttpRequest& request);
};
