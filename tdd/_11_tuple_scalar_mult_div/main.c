/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/12 11:56:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

void print_tuple(t_tuple tuple)
{
	printf("(%f, %f, %f, %i)\n", tuple.x, tuple.y, tuple.z, tuple.w);
}

int main(int argc, char *argv[])
{	
	if (argc != 5)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_tuple *a = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	float b = atof(argv[4]);
	t_tuple *c = tuple_scalar_mult(*a, b);
	print_tuple(*c);
	c = tuple_scalar_div(*a, b);
	print_tuple(*c);
	ft_free_trashman(ft_get_mem_address());
	return (0);
}