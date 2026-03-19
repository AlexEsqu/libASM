#include "../inc/libft.h"

// Returns the value difference between the first different characters in a character string
int ft_strcmp_in_C(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
