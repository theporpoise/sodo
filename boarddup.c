/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boarddup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:37:54 by mgould            #+#    #+#             */
/*   Updated: 2016/11/06 20:38:27 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		**boarddup(int **board)
{
	int		***board_copy;
	int		i;
	int		j;

	board_copy = (int***)malloc(sizeof(int**) * 9);
	i = 0;
	while (i < 9)
	{
		board[i] = (int*)malloc(sizeof(**board) * 9);
		j = 0;
		while (j < 9)
		{
			board_copy[i][j] = board[i][j];
			j++;
		}
		i++;
	}
	return (board_copy);
}
