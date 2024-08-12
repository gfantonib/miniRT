/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:32:49 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 16:25:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple* tuple_minus(t_tuple a, t_tuple b)
{
	t_tuple *tuple;

	tuple = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
	ft_collect_mem(tuple);
	tuple->x = a.x - b.x;
	tuple->y = a.y - b.y;
	tuple->z = a.z - b.z;
	tuple->w = a.w - b.w;
	return (tuple);
}

t_tuple* tuple_neg(t_tuple a)
{
	t_tuple *tuple;

	tuple = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
	ft_collect_mem(tuple);
	tuple->x = a.x * -1;
	tuple->y = a.y * -1;
	tuple->z = a.z * -1;
	tuple->w = a.w * -1;
	return (tuple);
}