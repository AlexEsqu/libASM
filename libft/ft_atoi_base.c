#include "../inc/libft.h"

int ft_atoi_base_in_C(char *str, char *base)
{
	int baseLen = ft_strlen(base);
	int result = 0;

	while (*str)
	{
		int		currentValue = 0;
		char*	currentChar = base;
		while (*currentChar != *str)
		{
			currentValue++;
			currentChar++;
		}
		result = result * baseLen;
		result += currentValue;
		str++;
	}
	return result;
}
