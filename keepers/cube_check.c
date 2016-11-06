#include "sudoku.h"//<stdlib.h>

//int square_check(int cube);

int ***row_check(int ***cube)
{
	int *row;
	int i;
	int j;
	int k;

	row = (int*)malloc(sizeof(*row) * 10);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			row[cube[i][j][0]] += cube[i][j][0] > 0 ? 1 : 0;
			// if cube[i][j][k] then Row[nbr] = 1;
			k = 0;
			while (k < 9)
			{
				cube[i][j][k] += row[k];
				k++;
			}
			j++;
		}
		i++;
	}
	free(row);
	return (cube);
}

int ***col_check(int ***cube)
{
	int *col;
	int i;
	int j;
	int k;

	col = (int*)malloc(sizeof(*col) * 9);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			col[cube[i][j][0]] += cube[i][j][0] > 0 ? 1 : 0;
			k = 0;
			while (k < 9)
			{
				cube[j][i][k] += col[k];
				k++;
			}
			j++;
		}
		i++;
	}
	free(col);
	return (cube);
}

int		***eliminate(int ***cube)
{
	int flag;
	int i;
	int j;
	int k;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (cube[i][j][0])
			{
				j++;
				continue;
			}
			k = 1;
			flag = 0;
			while (k < 10)
			{
				if (!cube[i][j][k] && flag == 0)
					flag = k;
				else
					flag = -1;
				k++;
			}
			if (flag > 0)
				cube[i][j][0] = flag;
			j++;
		}
		i++;
	}
	return (cube);
}
/*
[nbr,1,2,3,4,5,6,7,8,9]
[nbr,1,0,0,0,0,1,0,0,1]
*/








