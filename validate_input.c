/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:49:03 by mgould            #+#    #+#             */
/*   Updated: 2016/11/06 07:36:48 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	validate_input(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!((argv[i][j] == '.')
				|| (argv[i][j] >= '1' && argv[i][j] <= '9')))
			{
				return (1);
			}
			else if (j > 8)
				return (1);
			j++;
		}
		if (j != 9)
			return (1);
		i++;
		j = 0;
	}
	return (0);
}
