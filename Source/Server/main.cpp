#include <drogon/drogon.h>

int main()
{
    drogon::app()
        .loadConfigJson("configs/config.json")
        .run();
}