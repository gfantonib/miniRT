/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/09 17:54:43 by leduard2         ###   ########.fr       */
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
	if (argc != 4)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_tuple *a = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	t_tuple b = tuple_neg(*a);
	print_tuple(b);
	ft_free_trashman();;
	return (0);
}