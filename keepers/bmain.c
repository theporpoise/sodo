#include "sudoku.h"

int		main(int ac, char **av)
{
	if (validate_input(ac, av))
	{
		write(1, "fixme\n", 6);
	//	return (0);
	}

	int		***cube;

	cube = initialize_cube(av);

	render(cube);
	/*
	int		i;

	i = 0;
	while (i < 9)
	{
		cube[0][i][0] = i;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		ft_putchar(cube[0][0][i] + '0');
		i++;
	}

	cube = row_check(cube);
	i = 0;
	while (i < 10)
	{
		ft_putchar(cube[0][0][i] + '0');
		i++;
	}
	*/
	cube = eliminate(cube);
	ft_putchar('\n');
	render(cube);
	
	return (0);
}