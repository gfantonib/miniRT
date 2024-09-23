/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:19:18 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 14:40:42 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

#define PI 3.141592654

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