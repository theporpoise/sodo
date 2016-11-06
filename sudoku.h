#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "initialize_cube.c"
# include "render.c"
# include "get_free.c"

void	ft_putchar(char c);
void	render(int ***cube);
int		***make_cube(char **av);
int		***initialize_cube(char **av);

#endif