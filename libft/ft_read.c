#include "../inc/libft.h"

ssize_t ft_read_in_C(int fd, void* buf, size_t count)
{
	return (read(fd, buf, count));
}
