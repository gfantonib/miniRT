/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:32:49 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 10:23:25 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "tuple.h"
#include "matrix.h"
#include "error_exit.h"

t_matrix* create_point(float x, float y, float z)
{
	t_matrix *point;

	point = create_matrix(4, 1);
	point->matrix[0][0] = x;
	point->matrix[1][0] = y;
	point->matrix[2][0] = z;
	point->matrix[3][0] = POINT;
	return (point);
}

t_matrix* create_vector(float x, float y, float z)
{
	t_matrix *vector;

	vector = create_matrix(4, 1);
	vector->matrix[0][0] = x;
	vector->matrix[1][0] = y;
	vector->matrix[2][0] = z;
	vector->matrix[3][0] = VECTOR;
	return (vector);
}

float dot_prod(t_matrix veca, t_matrix vecb)
{
	float scalar;
	unsigned int i;
	
	if (veca.columns != 1 || vecb.columns != 1)
		error_exit("dot_prod() error: both arguments must be vectors\n");
	if (veca.rows != vecb.rows)
		error_exit("dot_prod() error: both arguments must have the same size\n");
	scalar = 0;
	i = 0;
	while (i < veca.rows)
	{
		scalar += veca.matrix[i][0] * vecb.matrix[i][0];
		i++;
	}
	return (scalar);
}

t_matrix *cross_prod(t_matrix veca, t_matrix vecb)
{
	if (veca.columns != 1 || vecb.columns != 1)
		error_exit("cross_prod() error: both arguments must be vectors\n");
	if (veca.rows != vecb.rows)
		error_exit("cross_prod() error: both arguments must have the same size\n");
	return (create_vector(veca.matrix[1][0] * vecb.matrix[2][0] - veca.matrix[2][0] * vecb.matrix[1][0],
		-1 * (veca.matrix[0][0] * vecb.matrix[2][0] - veca.matrix[2][0] * vecb.matrix[0][0]),
		veca.matrix[0][0] * vecb.matrix[1][0] - veca.matrix[1][0] * vecb.matrix[0][0]));
}

	// if (vec_a.w != 0 || vec_b.w != 0)
	// 	error_exit("cross_prod() error: both arguments must be vectors\n");
	// t_matrix result_vec;
	// result_vec.w = 0;
	// result_vec.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
	// result_vec.y = -1 * (vec_a.x * vec_b.z - vec_a.z * vec_b.x);
	// result_vec.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
	// return (result_vec) ;


	
// t_matrix* create_vector(float x, float y, float z)
// {
// 	t_tuple *vector;

// 	vector = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
// 	ft_collect_mem(vector);
// 	vector->x = x;
// 	vector->y = y;
// 	vector->z = z;
// 	vector->w = 0;
// 	return (vector);
// }

// int tuple_equal(t_tuple a, t_tuple b)
// {
// 	if (
// 			float_equal(a.x, b.x)
// 			&& float_equal(a.y, b.y)
// 			&& float_equal(a.z, b.z)
// 			&& a.w == b.w
// 		)
// 		return (1);
// 	return (0);
// }

// t_matrix tuple_add(t_ a, t_tuple b)
// {
// 	t_tuple tuple;

// 	tuple.x = a.x + b.x;y
// 	tuple.y = a.y + b.y;
// 	tuple.z = a.z + b.z;
// 	if(a.w == COLOR && b.w == COLOR)
// 		tuple.w = COLOR;
// 	else
// 		tuple.w = a.w + b.w;
// 	return (tuple);
// }