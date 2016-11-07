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
		printf("hey\n");
		return (cube);
	}
	else
	{
		printf("recursion\n");
		cube = cube_row_check(cube);
		cube = cube_col_check(cube);
		cube = cube_square_check(cube);
		return (cube_eliminate(cube));
	}
}
