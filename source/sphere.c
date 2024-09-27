/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:22:15 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/27 13:19:28 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "ray.h"
#include "error_exit.h"

t_sphere *create_sphere(t_matrix center)
{
	t_sphere *sphere;

	if (center.rows != 4 || center.columns != 1)
		error_exit("create_sphere() error: both arguments must be vertical vectors\n");
	sphere = (t_sphere *)calloc(1, sizeof(t_sphere));
	ft_collect_mem(sphere);
	sphere->center = create_point(center.matrix[0][0], center.matrix[1][0], center.matrix[2][0]);
	return (sphere);
}

float	*sphere_intersect(t_sphere sphere, t_ray ray)
{
	float a;
	float b;
	float c;
	t_matrix sphere_to_ray;
	float disc;
	float *intersect;
	
	sphere_to_ray = *matrix_minus(*ray.origin, *sphere.center);
	a = dot_prod(*ray.direction, *ray.direction);
	b = dot_prod(*ray.direction, sphere_to_ray) * 2;
	c = dot_prod(sphere_to_ray, sphere_to_ray) - 1;
	disc = powf(b, 2) - 4 * a * c;
	if (disc < 0)
		return (NULL);
	intersect = (float *)calloc(2, sizeof(float));
	intersect[0] = (-b - sqrtf(disc)) / (2 * a);
	intersect[1] = (-b + sqrtf(disc)) / (2 * a);
	return (intersect);
}