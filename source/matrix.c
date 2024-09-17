/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:30:58 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 10:21:44 by gfantoni         ###   ########.fr       */
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