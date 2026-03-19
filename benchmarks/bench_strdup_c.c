#include <string.h>
#include <stdlib.h>
#include "../inc/libft.h"

int main(void) {
    char *src = "The quick brown fox jumps over the lazy dog";
    volatile char *result = NULL;

    for (int i = 0; i < 1000000; i++) {
        __asm__("" : "+r" (src));
        result = ft_strdup_in_C(src);
        free((void *)result);
    }

    return result != NULL ? 0 : 1;
}
