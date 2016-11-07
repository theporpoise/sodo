/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rc_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:41:50 by mgould            #+#    #+#             */
/*   Updated: 2016/11/06 20:23:10 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_rc_safe(int val, int row, int col, int **board)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (val = board[row][i])
		{
			return 1;
		}
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (val = board[i][col])
		{
			return 1;
		}
	}
	return 0;
}
