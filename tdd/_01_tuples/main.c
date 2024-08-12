/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 14:35:30 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(void)
{
	t_tuple *point = create_point(1.5, 2.5, 3.5);
	t_tuple *vector = create_vector(1.5, 2.5, 3.5);

	printf("point (%f, %f, %f, %i)\n", point->x, point->y, point->z, point->w);
	printf("vector (%f, %f, %f, %i)\n", vector->x, vector->y, vector->z, vector->w);
	ft_free_trashman(ft_get_mem_address());
	return (0);
}