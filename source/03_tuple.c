/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:27:34 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 15:55:46 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "error_exit.h"

void normalize(t_tuple *vector)
{
	float	mag;

	mag = magnitude(*vector);
	vector->x /= mag;
	vector->y /= mag;
	vector->z /= mag;
	vector->w /= mag;
}

float dot_prod(t_tuple vec_a, t_tuple vec_b)
{
	if (vec_a.w != 0 || vec_b.w != 0)
		error_exit("dot_prod() error!\n");
	return (vec_a.x * vec_b.x + vec_a.y * vec_b.y + vec_a.z * vec_b.z);
}

t_tuple cross_prod(t_tuple vec_a, t_tuple vec_b)
{
	if (vec_a.w != 0 || vec_b.w != 0)
		error_exit("cross_prod() error!\n");
	t_tuple result_vec;
	result_vec.w = 0;
	result_vec.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
	result_vec.y = -1 * (vec_a.x * vec_b.z - vec_a.z * vec_b.x);
	result_vec.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
	return (result_vec) ;
}