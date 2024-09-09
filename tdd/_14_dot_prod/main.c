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
	ft_free_trashman();;
	return (0);
}