#include "sudoku.h"

int		*get_free(int *square);

int		***make_cube(char **av)
{
	int		***cube;
	int		i;
	int		j;

	cube = (int***)malloc(sizeof(int**) * 9);
	i = 0;
	while (i < 9)
	{
		cube[i] = (int**)malloc(sizeof(int*) * 9);
		j = 0;
		while (j < 9)
		{
			cube[i][j] = (int*)malloc(sizeof(int) * 9);
			j++;
		}
		j = 0;
		while (j < 9)
		{
			if (av[i + 1][j] == '.')
				cube[i][j][0] = 0;
			else
				cube[i][j][0] = av[i + 1][j] - '0';
			j++;
		}
		i++;
	}
	return (cube);
}

int		***initialize_cube(av)
{
	int		***cube;
	int		i;
	int		j;

	cube = make_cube(av);
	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			cube[i][j] = get_free(cube[i][j])
		}
	}
	return (cube);
}
