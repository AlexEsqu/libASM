#include "libft.h"

// Returns the size in characters of a character string
size_t ft_strlen(const char* str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return len;
}
