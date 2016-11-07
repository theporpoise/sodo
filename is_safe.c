#include "sudoku.h"

int		is_safe(int val, int row, int col)
{
	return (is_rc_safe(val, row, col) && is_square_safe(val, row, col));
}

