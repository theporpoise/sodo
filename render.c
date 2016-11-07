#include "sudoku.h"

void	render(int **board)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (board[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar(board[i][j][0] + '0');
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\b');
		ft_putchar('\n');
		i++;
	}
}
