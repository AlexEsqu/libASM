#include <string.h>
#include <stdlib.h>
#include "../../inc/libft.h"

int main(void) {
    char *src = "The quick brown fox jumps over the lazy dog";
    char buf[1024];
    volatile char *result = NULL;

    for (int i = 0; i < 10000000; i++) {
        __asm__("" : "+r" (src));
        result = ft_strcpy(buf, src);
    }

    return result != NULL ? 0 : 1;
}
