/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:17:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/27 11:04:13 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "error_exit.h"

t_ray *create_ray(t_matrix origin, t_matrix direction)
{
	t_ray *ray;

	if (origin.rows != 4 || origin.columns != 1 || direction.rows != 4 || direction.columns != 1)
		error_exit("create_ray() error: both arguments must be vertical vectors\n");
	ray = (t_ray *)calloc(1, sizeof(t_ray));
	ft_collect_mem(ray);
	ray->origin = create_point(origin.matrix[0][0], origin.matrix[1][0], origin.matrix[2][0]);
	ray->direction = create_vector(direction.matrix[0][0], direction.matrix[1][1], direction.matrix[2][0]);
	return (ray);
}

t_matrix	*position(t_ray ray, float t)
{
	return(matrix_add(*ray.origin, *matrix_scalar_mult(*ray.direction, t)));
}