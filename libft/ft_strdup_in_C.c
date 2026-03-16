#include "../inc/libft.h"

// Returns a pointer to a new string which is a duplicate of the string s.
char *ft_strdup_in_C(const char *s)
{
	size_t len;
	char *dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
