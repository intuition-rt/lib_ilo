#include <stdio.h>

#include "src/trame.h"

int main(void)
{
    char *p = build_trame(
        "set_wifi_credentials", {
            { "ssid", "my_super_ssid" },
            { "password", "12345678" },
        }
    );

    printf("[%s]\n", p);
}
