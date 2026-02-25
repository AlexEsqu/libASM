#include "libft_C/libft.h"
#include <stdio.h>

void main()
{
	// STRLEN

	char* str = "hellooo0";
	printf("%s is of length %ld\n", str, ft_strlen(str));

	// STRCPY

	char	buf[42];
	char*	ptr;

	ptr = ft_strcpy(buf, str);
	printf("strcpy prints: [%s]\n", buf);
}
