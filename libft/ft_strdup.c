#include "../inc/libft.h"

// Returns a pointer to a new string which is a duplicate of the string s.
char	*ft_strdup_in_C(const char *s)
{
	size_t	len = ft_strlen(s);

	char	*copy = malloc(len + 1);
	if (!copy)
		return (NULL);

	ft_strcpy(copy, s);
	return (copy);
}
