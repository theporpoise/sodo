/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:38:41 by mgould            #+#    #+#             */
/*   Updated: 2016/11/06 20:38:45 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		***initialize_board(char **av)
{
	int		**board;
	int		i;
	int		j;

	board = (int**)malloc(sizeof(*board) * 9);
	i = 0;
	while (i < 9)
	{
		board[i] = (int*)malloc(sizeof(**board) * 9);
		j = 0;
		while (j < 9)
		{
			if (av[i + 1][j] == '.')
				board[i][j] = 0;
			else
				board[i][j] = av[i + 1][j] - '0';
			j++;
		}
		i++;
	}
	return (board);
}
