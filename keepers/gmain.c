#include "gsudoku.h"

int		main(int ac, char **av)
{
	if (validate_input(ac, av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	// validate input confirmed with validate script.

	int		***cube;

	cube = initialize_cube(av);
	// initialize fixed!

	//print_cube_bools(cube);
	//printing bools fixed!  this is a godo function for bug finding.
	
	render(cube);
	// render cube working well.
	ft_putchar('\n');
	
	/*
	I don't htink tihs kind of testing will work b/c of how the bools are set up.
	int		i;
	i = 0;
	while (i < 9)
	{
		cube[0][i][0] = i;
		i++;
	}
	render(cube);
	ft_putchar('\n');
	i = 0;
	while (i < 10)
	{
		ft_putchar(cube[0][0][i] + '0');
		i++;
	}
	*/
	/*
	cube = row_check(cube);
	i = 0;
	while (i < 10)
	{
		ft_putchar(cube[0][0][i] + '0');
		i++;
	}
	*/
	
	//initialize fixed, checking eliminate

	cube = eliminate(cube);
	render(cube);
	ft_putchar('\n');

	return (0);
}
