int		is_square_safe(int val, int row, int col)
{
	int		row_min;
	int		col_min;
	int		i;
	int		j;

	row = (row / 3 + 1) * 3;
	col = (col / 3 + 1) * 3;
	row_min = row - 3;
	col_min = col - 3;
	i = 0;
	j = 0;
	while (row_min + i < row)
	{
		while (col_min + j < col)
		{
			if (val == board[i][j])
				return (1);
		}
	}
	return (0);
}
