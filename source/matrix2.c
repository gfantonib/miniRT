/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:17:57 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/22 12:15:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "error_exit.h"

static void build_cofactor_matrix(t_matrix *inv, t_matrix matrix);
static void divide_by_det(t_matrix *inv, float det);

float determinant(t_matrix matrix)
{
	t_matrix		*sub_matrix;
	unsigned int	j;
	float			det;
	
	if (matrix.rows != matrix.columns)
		error_exit("determinant() error: matrix must be squared\n");
	else if (matrix.rows == 1 && matrix.columns == 1)
		return (matrix.matrix[0][0]);
	det = 0;
	j = 0;
	while (j < matrix.columns)
	{
		sub_matrix = submatrix(matrix, 0, j);
		if (j % 2 == 0)
			det += matrix.matrix[0][j] * determinant(*sub_matrix);
		else
			det += -(matrix.matrix[0][j] * determinant(*sub_matrix));
		j++;
	}
	return (det);
}

t_matrix *inverse(t_matrix matrix)
{
	t_matrix		*inv;
	float			det;
	
	if (matrix.rows != matrix.columns)
		error_exit("inverse() error: matrix must be squared\n");
	det = determinant(matrix);
	if (det == 0)
		error_exit("inverse() error: cannot inverse matrix with determinant = 0\n");
	inv = create_matrix(matrix.rows, matrix.columns);
	build_cofactor_matrix(inv, matrix);
	inv = matrix_transpose(*inv);
	divide_by_det(inv, det);
	return (inv);
}

static void build_cofactor_matrix(t_matrix *inv, t_matrix matrix)
{
	unsigned int i;
	unsigned int j;
	
	i = 0;
	while (i < inv->rows)
	{
		j = 0;
		while (j < inv->columns)
		{
			if ((i + j) % 2 == 0)
				inv->matrix[i][j] = determinant(*submatrix(matrix, i, j));
			else
				inv->matrix[i][j] = -(determinant(*submatrix(matrix, i, j)));
			j++;
		}
		i++;
	}
}

static void divide_by_det(t_matrix *inv, float det)
{
	unsigned int i;
	unsigned int j;
	
	i = 0;
	while (i < inv->rows)
	{
		j = 0;
		while (j < inv->columns)
		{
			inv->matrix[i][j] = inv->matrix[i][j] / det;
			j++;
		}
		i++;
	}
}

t_matrix *matrix_add(t_matrix ma, t_matrix mb)
{
	unsigned int i;
	unsigned int j;
	t_matrix *mc;
	
	if (ma.rows != mb.rows || ma.columns != mb.columns)
		error_exit("matrix_add() error: trying to add matrices of different sizes\n");
	mc = create_matrix(ma.rows, mb.columns);
	i = 0;
	while (i < ma.rows)
	{
		j = 0;
		while (j < ma.columns)
		{
			mc->matrix[i][j] = ma.matrix[i][j] + mb.matrix[i][j];
			j++;
		}
		i++;
	}
	return (mc);
}