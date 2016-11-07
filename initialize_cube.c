#include "sudoku.h"

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

int		***initialize_cube(char **av)
{
	int		***cube;
	int		i;
	int		j;
	int		k;

	cube = make_cube(av);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			k = 1;
			while (k < 10)
			{
				if (cube[i][j][0] > 0)
					cube[i][j][k] = 1;
				else
					cube[i][j][k] = 0;
				k++;
			}
			j++;
		}
		i++;
	}
	return (cube);
}

int		***copy_cube(int ***cube)
{
	int		***cube_copy;
	int		i;
	int		j;
	int		k;

	cube_copy = (int***)malloc(sizeof(int**) * 9);
	i = 0;
	while (i < 9)
	{
		cube_copy[i] = (int**)malloc(sizeof(int*) * 9);
		j = 0;
		while (j < 9)
		{
			cube_copy[i][j] = (int*)malloc(sizeof(int) * 9);
			j++;
		}
		j = 0;
		while (j < 9)
		{
			k = 0;
			while (k < 10)
			{
				cube_copy[i][j][k] = cube[i][j][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (cube_copy);
}