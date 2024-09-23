/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:32:49 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 11:15:47 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		error_exit("dot_prod() error: both arguments must be vertical vectors\n");
	if (veca.rows != vecb.rows)
		error_exit("dot_prod() error: both arguments must have the same number of rows\n");
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
		error_exit("cross_prod() error: both arguments must be vertical vectors\n");
	if (veca.rows != 4 || vecb.rows != 4)
		error_exit("cross_prod() error: both arguments must have four rows\n");
	return (create_vector(veca.matrix[1][0] * vecb.matrix[2][0] - veca.matrix[2][0] * vecb.matrix[1][0],
		-1 * (veca.matrix[0][0] * vecb.matrix[2][0] - veca.matrix[2][0] * vecb.matrix[0][0]),
		veca.matrix[0][0] * vecb.matrix[1][0] - veca.matrix[1][0] * vecb.matrix[0][0]));
}
