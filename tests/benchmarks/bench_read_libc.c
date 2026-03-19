#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    // Setup test file
    int setup_fd = open("/tmp/bench_read_libc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char *content = "The quick brown fox jumps over the lazy dog\n";
    for (int i = 0; i < 1000; i++) {
        write(setup_fd, content, strlen(content));
    }
    close(setup_fd);

    char buf[4096];
    volatile ssize_t result = 0;

    for (int i = 0; i < 50000; i++) {
        int fd = open("/tmp/bench_read_libc.txt", O_RDONLY);
        if (fd < 0) return 1;
        result = read(fd, buf, sizeof(buf));
        close(fd);
    }

    unlink("/tmp/bench_read_libc.txt");
    return result > 0 ? 0 : 1;
}
