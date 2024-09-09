/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:27:34 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/09 17:41:43 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tuple.h"

t_tuple normalize(t_tuple vector)
{
	t_tuple norm_vec;
	float	mag;

	mag = magnitude(vector);
	norm_vec.x = vector.x / mag;
	norm_vec.y = vector.y / mag;
	norm_vec.z = vector.z / mag;
	norm_vec.w = vector.w / mag;
	return (norm_vec);
}

float dot_prod(t_tuple vec_a, t_tuple vec_b)
{
	if (vec_a.w != 0 || vec_b.w != 0)
	{
		ft_printf_fd(STDERR_FILENO, "dot_prod() error!\n");
		exit (1);
	}
	return (vec_a.x * vec_b.x + vec_a.y * vec_b.y + vec_a.z * vec_b.z);
}

t_tuple cross_prod(t_tuple vec_a, t_tuple vec_b)
{
	if (vec_a.w != 0 || vec_b.w != 0)
	{
		ft_printf_fd(STDERR_FILENO, "cross_prod() error!\n");
		exit (1);
	}
	t_tuple result_vec;
	result_vec.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
	result_vec.y = -1 * (vec_a.x * vec_b.z - vec_a.z * vec_b.x);
	result_vec.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
	return (result_vec) ;
}