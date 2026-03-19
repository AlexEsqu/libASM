#include "../inc/libft.h"

// Returns the size in characters of a character string
size_t ft_strlen_in_C(const char* str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return len;
}
