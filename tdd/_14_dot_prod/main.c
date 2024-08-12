/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/12 16:46:07 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(int argc, char *argv[])
{	
	if (argc != 7)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_tuple *vec_a = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	t_tuple *vec_b = create_vector(atof(argv[4]), atof(argv[5]), atof(argv[6]));
	float scalar = dot_prod(*vec_a, *vec_b);
	printf("%f\n", scalar);
	ft_free_trashman(ft_get_mem_address());
	return (0);
}