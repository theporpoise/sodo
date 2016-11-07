#include "sudoku.h"

int		***initialize_board(char **av)
{
	int		**board;
	int		i;
	int		j;

	board = (int**)malloc(sizeof(*board) * 9);
	i = 0;
	while (i < 9)
	{
		board[i] = (int*)malloc(sizeof(**board) * 9);
		j = 0;
		while (j < 9)
		{
			if (av[i + 1][j] == '.')
				board[i][j] = 0;
			else
				board[i][j] = av[i + 1][j] - '0';
			j++;
		}
		i++;
	}
	return (board);
}
