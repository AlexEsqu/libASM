#include "../inc/libft.h"

ssize_t ft_write_in_C(int fd, void* buf, size_t count)
{
	return (write(fd, buf, count));
}
