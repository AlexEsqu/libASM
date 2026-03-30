#include "../inc/libft.h"

// Returns the size in characters of a character string
size_t ft_strlen_in_C(const char* str)
{
	size_t len = 0;
	size_t i = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}

	return len;
}
