#include <string.h>
#include <stdlib.h>
#include "../../inc/libft.h"

int main(void) {
    char *str = "The quick brown fox jumps over the lazy dog";
    volatile size_t result = 0;

    for (int i = 0; i < 100000000; i++) {
        __asm__("" : "+r" (str));
        result = ft_strlen_in_C(str);
    }

    return result > 0 ? 0 : 1;
}
