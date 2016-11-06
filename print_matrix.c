/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:41:42 by mgould            #+#    #+#             */
/*   Updated: 2016/11/05 18:34:37 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(c)
{
	write(1, &c, 1);
}

void	print_matrix(int **matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar('0' + matrix[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		j = 0;
		ft_putchar('\b');
		ft_putchar('\n');
	}
}
