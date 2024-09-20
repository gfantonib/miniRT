/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/13 11:25:44 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(int argc, char *argv[])
{	
	if (argc != 4)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_tuple *vec = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	normalize(vec);
	float mag = magnitude(*vec);
	printf("%f\n", mag);
	ft_free_trashman();
	return (0);
}