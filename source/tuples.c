/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:32:49 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 14:23:25 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple* create_point(float x, float y, float z)
{
	t_tuple *point;

	point = (t_tuple *)malloc(sizeof(t_tuple));
	ft_collect_mem(point);
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = 1;
	return (point);
}