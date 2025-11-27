#ifndef UTIL_H
    #define UTIL_H

    #include <stddef.h>

void *xmalloc(size_t size);
void die(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

#endif
