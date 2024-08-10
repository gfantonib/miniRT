/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:32:49 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 16:25:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple* create_point(float x, float y, float z)
{
	t_tuple *point;

	point = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
	ft_collect_mem(point);
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = 1;
	return (point);
}

t_tuple* create_vector(float x, float y, float z)
{
	t_tuple *vector;

	vector = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
	ft_collect_mem(vector);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = 0;
	return (vector);
}

int float_equal(float a, float b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

int tuple_equal(t_tuple a, t_tuple b)
{
	if (
			float_equal(a.x, b.x)
			&& float_equal(a.y, b.y)
			&& float_equal(a.z, b.z)
			&& a.w == b.w
		)
		return (1);
	return (0);
}

t_tuple* tuple_add(t_tuple a, t_tuple b)
{
	t_tuple *tuple;

	tuple = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
	ft_collect_mem(tuple);
	tuple->x = a.x + b.x;
	tuple->y = a.y + b.y;
	tuple->z = a.z + b.z;
	tuple->w = a.w + b.w;
	return (tuple);
}