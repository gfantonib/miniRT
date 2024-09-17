/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:30:58 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 12:15:28 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"

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
	int rows;
	int columns;

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
	int ma_rows;
	int ma_columns;
	int result;
	
	if (ma.columns != mb.rows)
	{
		ft_printf_fd(STDERR_FILENO, "matrix_matrix_mult() error!\n");
		exit(1);
	}
	t_matrix *mc;
	mc = (t_matrix *)calloc(sizeof(t_matrix), 1);
	mc->matrix = create_matrix(ma.rows, mb.columns);
	mc->rows = ma.rows;
	mc->columns = mb.columns;
	ma_rows = 0;
	ma_columns = 0;
	while (ma_rows < ma.rows)
	{
		ma_columns = 0;
		while (ma_columns < ma.columns)
		{
			result += ma.matrix[ma_rows][ma_columns] * mb.matrix[ma_columns][ma_rows];
			ma_columns++;
		}
		mc->matrix[ma_rows][] = result;
		ma_rows++;
	}
}