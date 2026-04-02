#include "../inc/libft.h"
#include "stdio.h"



int main(void)
{
	char*	intInStr = "10";
	char*	ftInStr = "101010";
	char*	baseBinary = "01";
	char*	baseDecary = "0123456789";
	printf("%s in base %s is %d\n", intInStr, baseDecary, ft_atoi_base_in_C(intInStr, baseDecary));
	printf("%s in base %s is %d\n", intInStr, baseBinary, ft_atoi_base_in_C(intInStr, baseBinary));
	printf("%s in base %s is %d\n", ftInStr, baseBinary, ft_atoi_base_in_C(ftInStr, baseBinary));
	printf("%s in base %s is %d\n", intInStr, baseDecary, ft_atoi_base(intInStr, baseDecary));
	printf("%s in base %s is %d\n", intInStr, baseBinary, ft_atoi_base(intInStr, baseBinary));
	printf("%s in base %s is %d\n", ftInStr, baseBinary, ft_atoi_base(ftInStr, baseBinary));

	return (0);
}
