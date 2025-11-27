#include <limits.h>
#include <stdio.h>

#include "trame.h"
#include "util.h"

char *stringify_trame_param_int(int value)
{
    unsigned long buff_size = countof(xcat(-INT_MAX)) + 1;
    char *ret = xmalloc(buff_size);

    snprintf(ret, buff_size, "%d", value);
    return ret;
}

char *stringify_trame_param_s(char *value)
{
    /* nothing to do! */
    return value;
}
