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

	print_cube_bools(cube);
	render(cube);
	ft_putchar('\n');

	cube = cube_row_check(cube);
	cube = cube_col_check(cube);
	cube = cube_square_check(cube);

	cube = cube_eliminate(cube);

	print_cube_bools(cube);
	render(cube);

	//picker(cube);
	
	return (0);
}