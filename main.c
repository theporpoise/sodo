/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:41:42 by mgould            #+#    #+#             */
/*   Updated: 2016/11/05 16:43:07 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(c)
{
	write(1, &c, 1);
}

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
		else if (arg[i] == '.')
		{
			row[j] = 0;
			j++;
		}
		i++;
	}
	return (row);
}

int main(int argc, char **argv)
{
	int **matrix;
	int *row;
	int i;
	int j;

	argc = 0;
	i = 0;
	j = 0;
	row = (int*)malloc(sizeof(int) * 10);
	matrix = (int**)malloc(sizeof(int*) * 9);
	while(i < 9)
	{
		matrix[i] = (int*)malloc(sizeof(int) * 10);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		row = make_row(argv[i + 1]);
		//printf("row[0] is:%d\n", row[0]);
		//ft_putchar('0' + i);
		while (j < 9)
		{
		matrix[i][j] = row[j];
		//printf("row[j] is:%d\n", row[j])
		ft_putchar('0' + matrix[i][j]);
		//ft_putchar('0' + j);
		ft_putchar(' ');
		j++;
		}
		i++;
		j = 0;
		ft_putchar('\b');
		ft_putchar('\n');
	}

	ft_putchar('\n');
	i = 0;
	char *temp = "9...7....";
	printf("before make row\n");
	//printf("row entry 8 is:%d\n", row[8]);
	row = make_row(temp); 
	//printf("after make row\n");
	//printf("row entry 8 is:%d\n", row[8]);
	while(i < 9) 
	{
		ft_putchar(('0' + row[i]));
		//printf("you got here\n");
		i++;
	}
	
	return (0);

}
