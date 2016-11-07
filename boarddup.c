#include "sudoku.h"

int		**boarddup(int **board)
{
	int		***board_copy;
	int		i;
	int		j;

	board_copy = (int***)malloc(sizeof(int**) * 9);
	i = 0;
	while (i < 9)
	{
		board[i] = (int*)malloc(sizeof(**board) * 9);
		j = 0;
		while (j < 9)
		{
			board_copy[i][j] = board[i][j];
			j++;
		}
		i++;
	}
	return (board_copy);
}