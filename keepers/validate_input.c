/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:49:03 by mgould            #+#    #+#             */
/*   Updated: 2016/11/05 21:17:52 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	validate_input(int argc, char **argv)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (i < (argc - 1))
	{
		while (argv[i][j])
		{
			if	(!(argv[i][j] == '.' || (argv[i][j] >= '1' && argv[i][j] <= '9')))
			{
				printf("argiv is:%c", argv[i][j]);
				printf("j is:%d\n", j);
				return (1);
			}
			else if (j > 8)
			{
				printf("j greater than 8\n");
				return (1);
			}
			j++;
		}
		if (j != 9)
			printf("j is %d", j);
			return (1);
		i++;
		j = 0;
	}
	return (0);
}
