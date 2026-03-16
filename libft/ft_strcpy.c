#include "../inc/libft.h"

// copy the string pointed to by src, into a string at the buffer pointed to by dst.  The programmer is
// responsible for allocating a destination buffer large enough, that is, strlen(src) + 1.
char *ft_strcpy(char *restrict dst, const char *restrict src)
{
	char* curr = dst;
	while (*src)
	{
		*curr = *src;
		curr++;
		src++;
	}
	*curr = '\0';
	return dst;
}
