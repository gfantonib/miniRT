/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:30:58 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/21 10:45:18 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include "error_exit.h"

t_matrix *create_matrix(unsigned int rows, unsigned int columns)
{
	unsigned int i;
	t_matrix *matrix;
	
	matrix = (t_matrix *)calloc(1, sizeof(t_matrix));
	ft_collect_mem(matrix);
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->matrix = (float **)calloc(rows, sizeof(float *));
	ft_collect_mem(matrix->matrix);
	i = 0;
	while(i < rows)
	{
		matrix->matrix[i] = (float *)calloc(columns, sizeof(float));	
		ft_collect_mem(matrix->matrix[i]);
		i++;
	}
	return (matrix);
}

int matrix_equal(t_matrix ma, t_matrix mb)
{
	unsigned int rows;
	unsigned int columns;

	if (ma.rows != mb.rows || ma.columns != mb.columns)
		return (0);
	rows = 0;
	columns = 0;
	while (rows < ma.rows)
	{
		columns = 0;
		while (columns < ma.columns)
		{
			if (!float_equal(ma.matrix[rows][columns], mb.matrix[rows][columns]))
				return (0);
			columns++;
		}
		rows++;
	}
	return (1);
}

t_matrix *matrix_matrix_mult(t_matrix ma, t_matrix mb)
{
	unsigned int count[3];
	float result;
	t_matrix *mc;

	if (ma.columns != mb.rows)
		error_exit("matrix_matrix_mult() error: ma.columns must be equal to mb.rows\n");
	mc = create_matrix(ma.rows, mb.columns);
	count[0] = 0;
	while (count[0] < ma.rows)
	{
		count[1] = 0;
		while (count[1] < mb.columns)
		{
			count[2] = 0;
			result = 0;
			while (count[2] < ma.columns)
			{
				result += ma.matrix[count[0]][count[2]] * mb.matrix[count[2]][count[1]];
				count[2]++;
			}
			mc->matrix[count[0]][count[1]++] = result;
		}
		count[0]++;
	}
	return (mc);
}

t_matrix *matrix_transpose(t_matrix matrix)
{
	unsigned int i;
	unsigned int j;
	
	t_matrix *result;
	result = create_matrix(matrix.columns, matrix.rows);
	i = 0;
	while (i < result->rows)
	{
		j = 0;
		while (j < result->columns)
		{
			result->matrix[i][j] = matrix.matrix[j][i];
			j++;
		}
		i++;
	}
	return (result);
}

t_matrix *submatrix(t_matrix matrix, unsigned int rm_row, unsigned int rm_column)
{
	unsigned int i;
	unsigned int j;
	t_matrix *new_matrix;

	if (matrix.rows - 1 < rm_row || matrix.columns - 1 < rm_column)
		error_exit("submatrix() error: trying to remove a non existing row or column\n");
	new_matrix = create_matrix(matrix.rows - 1, matrix.columns - 1);
	i = 0;
	while(i < new_matrix->rows)
	{
		new_matrix->matrix[i] = (float *)calloc(new_matrix->columns, sizeof(float));
		ft_collect_mem(new_matrix->matrix[i]);
		j = 0;
		while (j < new_matrix->columns)
		{
			new_matrix->matrix[i][j] = matrix.matrix[i + (i >= rm_row)][j + (j >= rm_column)];
			j++;
		}
		i++;
	}
	return (new_matrix);
}