#include <stdio.h>

#include <stdlib.h>

int main()
{
	int	*num;
	int dif;

	num = malloc(4 * (sizeof(int)));
	dif = &num[3] - &num[1];

	printf("diff: %d\n", dif);
	free (num);
	return (0);
}