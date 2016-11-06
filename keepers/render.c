#include "sudoku.h"

void	render(int ***cube)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (cube[i][j][0] == 0)
				ft_putchar('.');
			else
				ft_putchar(cube[i][j][0] + '0');
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\b');
		ft_putchar('\n');
		i++;
	}
}
