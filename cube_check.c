#include "sudoku.h"//<stdlib.h>

int		***row_check(int ***cube, int row_index)
{
	int *row;
	int i;
	int j;

	row = (int*)malloc(sizeof(*row) * 9);
	i = 0;
	while (i < 9)
	{
		row[cube[row_index][i][0] - 1] = cube[row_index][i][0] > 0 ? 1 : 0;
		// if cube[i][j][k] then Row[nbr] = 1;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			cube[row_index][i][j + 1] += row[j];
			j++;
		}
		i++;
	}
	free(row);
	return (cube);
}

int		***col_check(int ***cube, int col_index)
{
	int *col;
	int i;
	int j;

	col = (int*)malloc(sizeof(*col) * 9);
	i = 0;
	while (i < 9)
	{
		col[cube[i][col_index][0] - 1] = cube[i][col_index][0] > 0 ? 1 : 0;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			cube[i][col_index][j + 1] += col[j];
			j++;
		}
		i++;
	}
	free(col);
	return (cube);
}

int		***square_check(int ***cube, int row, int col)
{
	int		*square;
	int		row_min;
	int		col_min;
	int		i;
	int		j;
	int		k;

	square = (int*)malloc(sizeof(*square) * 9);
	row = (row / 3 + 1) * 3;
	col = (col / 3 + 1) * 3;
	row_min = row - 3;
	col_min = col - 3;
	i = 0;
	while (row_min + i < row)
	{
		j = 0;
		while (col_min + j < row)
		{
			square[cube[row_min + i][col_min + j][0] - 1] = \
			cube[row_min + i][col_min + j][0] > 0 ? 1 : 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (row_min + i < row)
	{
		j = 0;
		while (col_min + j < col)
		{
			k = 0;
			while (k < 9)
			{
				cube[row_min + i][col_min + j][k + 1] += square[k];
				k++;
			}
			j++;
		}
		i++;
	}
	free(square);
	return (cube);
}


int		***cube_row_check(int ***cube)
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
			j++;
		}
		j = 0;
		while (j < 9)
		{
			k = 1;
			while (k < 10)
			{
				cube[i][j][k] += row[k];
				k++;
			}
			j++;
		}
		j = 0;
		while (j < 9)
		{
			row[cube[i][j][0]] = 0;
			j++;
		}
		i++;
	}
	free(row);
	return (cube);
}

int		***cube_col_check(int ***cube)
{
	int *col;
	int i;
	int j;
	int k;

	col = (int*)malloc(sizeof(*col) * 10);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			col[cube[j][i][0]] += cube[j][i][0] > 0 ? 1 : 0;
			// if cube[i][j][k] then Row[nbr] = 1;
			j++;
		}
		j = 0;
		while (j < 9)
		{
			k = 1;
			while (k < 10)
			{
				cube[j][i][k] += col[k];
				k++;
			}
			j++;
		}
		j = 0;
		while (j < 9)
		{
			col[cube[j][i][0]] = 0;
			j++;
		}
		i++;
	}
	free(col);
	return (cube);
}

int		***cube_square_check(int ***cube)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < 9)
	{
		while (j < 9)
		{
			cube = square_check(cube, i, j);
			j += 3;
		}
		i += 3;
	}
	return (cube);
}

int		***cube_eliminate(int ***cube)
{
	int changed;
	int flag;
	int i;
	int j;
	int k;

	changed = 0;
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
				else if (!cube[i][j][k])
					flag = -1;
				k++;
			}
			if (flag > 0)
			{
				cube[i][j][0] = flag;
				changed = 1;
			}
			j++;
		}
		i++;
	}
	if (!changed)
	{
		return (cube);
	}
	else
	{
		cube = cube_row_check(cube);
		cube = cube_col_check(cube);
		cube = cube_square_check(cube);
		return (cube_eliminate(cube));
	}
}

/*
int		row_eliminate(int ****cube, int ***eliminated, int row)
{
	int flag;
	int i;
	int j;
	int k;

	i = 0;
	while (i < 9)
	{
		if (*cube[row][i][0])
		{
			i++;
			continue;
		}
		j = 1;
		flag = 0;
		while (j < 10)
		{
			if (!*cube[row][i][j] && flag == 0)
				flag = j;
			else if (!*cube[row][i][j])
				flag = -1;
			j++;
		}
		if (flag > 0)
		{
			*cube[row][i][0] = flag;
			k++;
		}
		i++;
	}
	return (k);
}

int		col_eliminate(int ****cube, int col)
{
	int flag;
	int i;
	int j;
	int k;

	i = 0;
	while (i < 9)
	{
		if (*cube[i][col][0])
		{
			i++;
			continue;
		}
		j = 1;
		flag = 0;
		while (j < 10)
		{
			if (!*cube[i][col][j] && flag == 0)
				flag = j;
			else if (!*cube[i][col][j])
				flag = -1;
			j++;
		}
		if (flag > 0)
		{
			*cube[i][col][0] = flag;
			k++;
		}
		i++;
	}
	return (k);
}

int		square_eliminate(int ****cube, int row, int col)
{
	row = (row / 3 + 1) * 3;
	col = (col / 3 + 1) * 3;
	i = row - 3;
	while (i < row)
	{
		j = col - 3;
		while (j < col)
		{
			if (*cube[i][j][0])
			{
				j++;
				continue;
			}
			k = 1;
			flag = 0;
			while (k < 10)
			{
				if (!*cube[i][j][k] && flag == 0)
					flag = k;
				else if (!*cube[i][j][k])
					flag = -1;
				k++;
			}
			if (flag > 0)
			{
				*cube[i][j][0] = flag;
				k++;
			}
			j++;
		}
		i++;
	}
	return (k);
}



int		***eliminate(int ***cube, int row, int col)
{
	int flag;

	flag = row_eliminate(&cube, row) + \
		   col_eliminate(&cube, col) + \
		   square_eliminate(&cube, row, col);


	if (!flag)
	{
		return (cube);
	}
	else
	{

	}
}
*/
/*
[nbr,1,2,3,4,5,6,7,8,9]
[nbr,1,0,0,0,0,1,0,0,1]
*/

