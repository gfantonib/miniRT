/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 14:24:05 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(void)
{
	t_tuple *point = create_point(1.5, 2.5, 3.5);

	printf("(%f, %f, %f, %i)", point->x, point->y, point->z, point->w);
	ft_printf("melvin\n");
	ft_free_trashman(ft_get_mem_address());
	return (0);
}