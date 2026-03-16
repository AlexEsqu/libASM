#include "inc/libft.h"
#include <stdio.h>

int main()
{
	// STRLEN

	printf("\nSTRLEN\n");
	char* str = "helloé";
	printf("\"%s\" is of length %ld\n", str, ft_strlen(str));
	printf("\"%s\" is of length %ld\n", str, strlen(str));
	printf("empty string is of size %ld\n", ft_strlen(""));
	printf("empty string is of size %ld\n", strlen(""));
	printf("\n");

	// STRCMP

	printf("\nSTRCMP\n");
	char* str2 = "holla";
	printf("\"%s\" and \"%s\" are of difference %d\n", str, str2, ft_strcmp(str, str2));
	printf("\"%s\" and \"%s\" are of difference %d\n", str, str2, strcmp(str, str2));
	printf("\"%s\" and \"%s\" are of difference %d\n", str, str, ft_strcmp(str, str));
	printf("\"%s\" and \"%s\" are of difference %d\n", str, str, strcmp(str, str));
	printf("\n");

	// STRCPY

	printf("\nSTRCPY\n");

	char	buf[42];
	char*	ptr;
	ptr = ft_strcpy(buf, str);
	printf("strcpy prints into the buffer [%s] and returns [%s]\n", buf, ptr);

	ptr = strcpy(buf, str);
	printf("strcpy prints into the buffer [%s] and returns [%s]\n", buf, ptr);
	printf("\n");

	return (0);
}
