#include "sudoku.h"

// call validate cube before picker
// if pos has no solution board fails
//

int		*lowest_boolcount_loc(int ***cube)
{
	int		*loc;
	int		i;
	int		j;
	int		k;
	int		bool_number;

	loc = (int*)malloc(sizeof(*loc) * 3);
	i = 0;
	loc[0] = 10;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (cube[i][j][0] > 0)
			{
				j++;
				continue;
			}
			k = 1;
			bool_number = 0;
			while (k < 10)
			{
				bool_number += !cube[i][j][k] ? 1 : 0;
				k++;
			}
			if (bool_number < loc[0])
			{
				loc[0] = bool_number;
				loc[1] = i;
				loc[2] = j;
			}
			j++;
		}
		i++;
	}
	return (loc);
}

/*
int		***picker(int ***cube)
{
	int		***cube2;
	int		*loc;
	int		i;

	loc = lowest_boolcount_loc(cube);

	i = 1;
	while (i < 3)
	{
		if (!cube[loc[1]][loc[2]][i])
		{
			cube[loc[1]][loc[2]][0] = i;
			cube2 = copy_cube(cube);
			cube_eliminate(cube2);
			ft_putchar('\n');
		render(cube2);
		}
		i++;
	}


	return (cube);
}*/