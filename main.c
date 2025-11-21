#include <stdio.h>

#include "src/trame.h"

int main(void)
{
    char *p = build_simple_trame("get_motors_ilo_acc");

    printf("[%s]\n", p);
}
