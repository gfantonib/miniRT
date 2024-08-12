/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/12 11:22:35 by gfantoni         ###   ########.fr       */
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
	if (argc != 7)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_tuple *a = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	t_tuple *b = create_vector(atof(argv[4]), atof(argv[5]), atof(argv[6]));
	t_tuple *c = tuple_minus(*a, *b);
	print_tuple(*c);
	ft_free_trashman(ft_get_mem_address());
	return (0);
}