#include <drogon/drogon.h>

int main()
{
    drogon::app()
        .loadConfigFile("configs/config.json")
        .run();
}