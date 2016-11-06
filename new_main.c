/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:35:04 by mgould            #+#    #+#             */
/*   Updated: 2016/11/05 18:40:22 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "make_matrix.c"
#include "print_matrix.c"

int main(int argc, char **argv)
{
	argc = 0;
	print_matrix(make_matrix(argv));

	return (0);
}
