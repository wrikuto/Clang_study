#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int	width;
	int height;
	int tall;
	int (*sum)(int, int, int);
} Cube;

int sum(int i, int j, int k)
{
	int rtn;

	rtn = 0;
	rtn = i * j * k;
	return (rtn);
}

Cube *create_struct(int i, int j, int k)
{
	Cube	*sum_cube;
	int		rtn;

	sum_cube = malloc(sizeof(Cube));

	sum_cube -> width = i;
	sum_cube -> height = j;
	sum_cube -> tall = k; 
	sum_cube -> sum = sum;	
	return (sum_cube);
}

int main()
{
	int rtn;
	int i, j, k;
	Cube	*sum_cube;

	i = 2;
	j = 3;
	k = 4;

	sum_cube = create_struct(i, j, k);
	rtn = sum_cube -> sum(sum_cube -> width, sum_cube -> height, sum_cube -> tall);

	printf("%dcm^3\n", rtn);
}