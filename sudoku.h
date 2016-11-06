#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "initialize_cube.c"
# include "ft_putchar.c"
# include "render.c"
# include "validate_input.c"
# include "cube_check.c"

void	ft_putchar(char c);
void	render(int ***cube);
void	print_cube_bools(int ***cube);
int		***make_cube(char **av);
int		***initialize_cube(char **av);
int		***row_check(int ***cube);
int		***eliminate(int ***cube);

#endif
