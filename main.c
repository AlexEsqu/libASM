#include "inc/libft.h"
#include <stdio.h>

int main()
{
	// STRLEN

	char* str = "hello";
	printf("%s is of length %ld\n", str, ft_strlen(str));

	// STRCMP

	char* str2 = "hello";
	printf("%s and %s are of difference %d\n", str, str2, ft_strcmp(str, str2));

	// // // STRCPY

	// char	buf[42];
	// char*	ptr;

	// ptr = ft_strcpy(buf, str);
	// printf("strcpy prints: [%s]\n", buf);

	return (0);
}
