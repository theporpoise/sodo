/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:27:21 by mgould            #+#    #+#             */
/*   Updated: 2016/11/05 18:41:55 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*make_row(char *arg)
{
	int i;
	int j;
	int *row;

	i = 0;
	j = 0;
	row = (int*)malloc(sizeof(int) * 10);
	while (arg[i])
	{
		if (arg[i] > '0' && arg[i] <= '9')
		{	
			row[j] = (arg[i] - '0');
			j++;
		}
		else if (arg[i] + '.')
		{
			row[j] = 0;
			j++;
		}
		i++;
	}
	return (row);
}
 

int **make_matrix(char **argv)
{
	int **matrix;
	int i;

	i = 0;
	matrix = (int**)malloc(sizeof(int*) * 9);
	while(i < 9)
	{
		matrix[i] = (int*)malloc(sizeof(int) * 10);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		matrix[i] = make_row(argv[i + 1]);
		i++;
	}
	return (matrix);
}
