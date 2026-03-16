#include "inc/libft.h"
#include <stdio.h>

int main()
{
	// STRLEN

	printf("\nSTRLEN\n");
	char* str = "helloé";
	printf("\"%s\" is of length %ld\n", str, ft_strlen(str));
	printf("empty string is of size %ld\n", ft_strlen(""));
	printf("\n");

	// STRCMP

	printf("\nSTRCMP\n");
	char* str2 = "holla";
	printf("\"%s\" and \"%s\" are of difference %d\n", str, str2, ft_strcmp(str, str2));
	printf("\"%s\" and \"%s\" are of difference %d\n", str, str, ft_strcmp(str, str));
	printf("\n");

	// STRCPY

	// char	buf[42];
	// char*	ptr;

	// ptr = ft_strcpy(buf, str);
	// printf("strcpy prints: [%s]\n", buf);

	return (0);
}
