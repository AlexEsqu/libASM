#include "../inc/libft.h"

int ft_atoi_base_in_C(char *str, char *base)
{
	int baseLen = ft_strlen(base);

	// CHECK BASE

	if (baseLen < 2)
		return (0);

	char* currBase = base;
	while (*currBase)
	{
		if (*currBase == '+')
			return (0);

		if (*currBase == '-')
			return (0);

		if (*currBase <= ' ') // whitespaces
			return (0);

		char* otherChar = currBase + 1;
		while (*otherChar)
		{
			if (*currBase == *otherChar)
				return (0);
			otherChar++;
		}
		currBase++;
	}

	// ATOI

	int result = 0;
	char* currStr = str;
	while (*currStr)
	{
		int		currentValue = 0;
		char*	currentChar = base;

		// find char value
		while (*currentChar != *currStr)
		{
			currentValue++;
			currentChar++;

			// exit character not in the base
			if (*currentChar == 0)
				return (0);
		}
		result = result * baseLen;
		result += currentValue;
		currStr++;
	}

	return result;
}
