/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:30:58 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/20 09:41:52 by gfantoni         ###   ########.fr       */
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

// t_matrix *matrix_matrix_mult(t_matrix ma, t_matrix mb)
// {
// 	int ma_rows;
// 	int ma_columns;
// 	int mb_rows;
// 	int mb_columns;
// 	int mc_rows;
// 	int mc_columns;
// 	int result;
// 	t_matrix *mc;
	
// 	if (ma.columns != mb.rows)
// 		error_exit("matrix_matrix_mult() error!\n");
// 	mc = create_matrix(ma.rows, mb.columns);
// 	ma_rows = 0;
// 	mc_rows = 0;
// 	mc_columns = 0;
// 	while (ma_rows < ma.rows)
// 	{
// 		mc_columns = 0;
// 		mb_columns = 0;
// 		while (mb_columns < mb.columns)
// 		{
// 			ma_columns = 0;
// 			mb_rows = 0;
// 			result = 0;
// 			while (ma_columns < ma.columns)
// 				result += ma.matrix[ma_rows][ma_columns++] * mb.matrix[mb_rows++][mb_columns];
// 			mc->matrix[mc_rows][mc_columns++] = result;;
// 			mb_columns++;
// 		}
// 		mc_rows++;
// 		ma_rows++;
// 	}
// 	return (mc);
// }

t_matrix *matrix_matrix_mult(t_matrix ma, t_matrix mb)
{
	unsigned int count[3];
	int result;
	t_matrix *mc;

	if (ma.columns != mb.rows)
		error_exit("matrix_matrix_mult() error!\n");
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

float det_two_by_two(t_matrix matrix)
{
	if (matrix.rows != 2 || matrix.columns != 2)
		error_exit("det_two_by_two() error!\n");
	return (matrix.matrix[0][0] * matrix.matrix[1][1]
		- matrix.matrix[0][1] * matrix.matrix[1][0]);
}