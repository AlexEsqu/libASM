#include "../inc/libft.h"

ssize_t ft_write(int fd, void* buf, size_t count)
{
	return (write(fd, buf, count));
}
