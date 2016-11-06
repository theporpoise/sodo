/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:35:04 by mgould            #+#    #+#             */
/*   Updated: 2016/11/05 21:08:42 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "make_matrix.c"
#include "print_matrix.c"
#include "validate_input.c"

int main(int argc, char **argv)
{
	if (validate_input(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_matrix(make_matrix(argv));

	return (0);
}
