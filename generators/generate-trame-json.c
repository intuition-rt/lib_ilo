#include <stdio.h>

// TODO: fixme
#include "../src/trame.c"

int main(void)
{
    printf("[\n");
    for (size_t i = 0; i < TRAME_COUNT; i++) {
        printf(" { ");
        printf("\"name\": \"%s\", ", TRAMES[i].name);
        printf("\"format\": \"%s\"", TRAMES[i].format);
        if (i + 1 < TRAME_COUNT)
            printf(" },\n");
        else
            printf(" }\n");
    }
    printf("]\n");
}
