#include <string.h>
#include <stdlib.h>
#include "../inc/libft.h"

int main(void) {
    char *s1 = "The quick brown fox jumps over the lazy dog";
    char *s2 = "The quick brown fox jumps over the lazy dog";
    volatile int result = 0;

    for (int i = 0; i < 50000000; i++) {
        __asm__("" : "+r" (s1), "+r" (s2));
        result = ft_strcmp_in_C(s1, s2);
    }

    return result == 0 ? 0 : 1;
}
