#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../inc/libft.h"

int main(void) {
    char *msg = "The quick brown fox jumps over the lazy dog\n";
    int fd = open("/tmp/bench_write_asm.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    volatile ssize_t result = 0;

    if (fd < 0) return 1;

    for (int i = 0; i < 100000; i++) {
        __asm__("" : "+r" (msg));
        result = ft_write(fd, msg, strlen(msg));
    }

    close(fd);
    unlink("/tmp/bench_write_asm.txt");
    return result > 0 ? 0 : 1;
}
