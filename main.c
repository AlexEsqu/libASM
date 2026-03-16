#include "inc/libft.h"
#include <stdio.h>

int main()
{
	// STRLEN

	char* str = "helloé";
	printf("%s is of length %ld\n", str, ft_strlen(str));

	// STRCMP

	char* str2 = "holla";
	printf("%s and %s are of difference %d\n", str, str2, ft_strcmp(str, str2));
	printf("%s and %s are of difference %d\n", str, str, ft_strcmp(str, str));

	// // // STRCPY

	// char	buf[42];
	// char*	ptr;

	// ptr = ft_strcpy(buf, str);
	// printf("strcpy prints: [%s]\n", buf);

	return (0);
}
