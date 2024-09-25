/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:19:18 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/25 18:01:54 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix *translation(float x, float y, float z)
{
	t_matrix *matrix;
	
	matrix = create_matrix(4, 4);
	matrix->matrix[0][0] = 1;
	matrix->matrix[1][1] = 1;
	matrix->matrix[2][2] = 1;
	matrix->matrix[3][3] = 1;
	matrix->matrix[0][3] = x;
	matrix->matrix[1][3] = y;
	matrix->matrix[2][3] = z;
	return (matrix);
}

t_matrix *scaling(float x, float y, float z)
{
	t_matrix *matrix;
	
	matrix = create_matrix(4, 4);
	matrix->matrix[0][0] = x;
	matrix->matrix[1][1] = y;
	matrix->matrix[2][2] = z;
	matrix->matrix[3][3] = 1;
	return (matrix);
}

t_matrix *rotate_x(float radians)
{
	t_matrix *matrix;
	matrix = create_matrix(4, 4);
	matrix->matrix[0][0] = 1;
	matrix->matrix[1][1] = cos(radians);
	matrix->matrix[1][2] = -sin(radians);
	matrix->matrix[2][1] = sin(radians);
	matrix->matrix[2][2] = cos(radians);
	matrix->matrix[3][3] = 1;
	return (matrix);
}

t_matrix *rotate_y(float radians)
{
	t_matrix *matrix;
	matrix = create_matrix(4, 4);
	matrix->matrix[0][0] = cos(radians);
	matrix->matrix[0][2] = sin(radians);
	matrix->matrix[1][1] = 1;
	matrix->matrix[2][1] = -sin(radians);
	matrix->matrix[2][2] = cos(radians);
	matrix->matrix[3][3] = 1;
	return (matrix);
}

t_matrix *rotate_z(float radians)
{
	t_matrix *matrix;
	matrix = create_matrix(4, 4);
	matrix->matrix[0][0] = cos(radians);
	matrix->matrix[0][1] = -sin(radians);
	matrix->matrix[1][0] = sin(radians);
	matrix->matrix[1][1] = cos(radians);
	matrix->matrix[2][2] = 1;
	matrix->matrix[3][3] = 1;
	return (matrix);
}