/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/12 14:27:51 by gfantoni         ###   ########.fr       */
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
	t_tuple *color_a = create_color(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	t_tuple *color_b = create_color(atof(argv[4]), atof(argv[5]), atof(argv[6]));
	t_tuple result_color = color_color_mult(*color_a, *color_b);
	print_tuple(result_color);
	result_color = tuple_add(*color_a, *color_b);
	print_tuple(result_color);
	result_color = tuple_minus(*color_a, *color_b);
	print_tuple(result_color);
	ft_free_trashman();
	return (0);
}