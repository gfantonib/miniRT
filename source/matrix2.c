/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:17:57 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/20 12:22:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include "error_exit.h"

// t_matrix *submatrix(t_matrix matrix, unsigned int rm_row, unsigned int rm_column)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	unsigned int	k;
// 	unsigned int	l;
// 	int				row_flag;
// 	int				column_flag;
// 	t_matrix *new_matrix;

// 	if (matrix.rows - 1 < rm_row || matrix.columns - 1 < rm_column)
// 		error_exit("submatrix() error!\n");
// 	new_matrix = (t_matrix *)calloc(1, sizeof(t_matrix));
// 	ft_collect_mem(new_matrix);
// 	new_matrix->rows = matrix.rows - 1;
// 	new_matrix->columns = matrix.columns - 1;
// 	new_matrix->matrix = (float **)calloc(new_matrix->rows, sizeof(float *));
// 	ft_collect_mem(new_matrix->matrix);
// 	row_flag = 0;
// 	i = 0;
// 	k = 0;
// 	while(i < new_matrix->rows)
// 	{
// 		if (i == rm_row && !row_flag)
// 		{
// 			row_flag = 1;
// 			k++;
// 			continue;
// 		}
// 		new_matrix->matrix[i] = (float *)calloc(new_matrix->columns, sizeof(float));	
// 		ft_collect_mem(new_matrix->matrix[i]);
// 		column_flag = 0;
// 		j = 0;
// 		l = 0;
// 		while (j < new_matrix->columns)
// 		{
// 			if (j == rm_column && column_flag == 0)
// 			{
// 				column_flag = 1;
// 				l++;
// 				continue;
// 			}
// 			new_matrix->matrix[i][j] = matrix.matrix[k][l];
// 			j++;
// 			l++;
// 		}
// 		i++;
// 		k++;
// 	}
// 	return (new_matrix);
// }

t_matrix *submatrix(t_matrix matrix, unsigned int rm_row, unsigned int rm_column)
{
	unsigned int i;
	unsigned int j;
	t_matrix *new_matrix;

	if (matrix.rows - 1 < rm_row || matrix.columns - 1 < rm_column)
		error_exit("submatrix() error!\n");
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

// float minor(t_matrix matrix, unsigned int row, unsigned int column)
// {
// 	t_matrix *sub_matrix;

// 	if (matrix.rows != matrix.columns)
// 		error_exit("minor() error!\n");
// 	if (matrix.rows == 1 && matrix.rows == 1)
// 		return (matrix.matrix[0][0]);
// 	sub_matrix = submatrix(matrix, row, column);
	
// }

float determinant(t_matrix matrix)
{	
	t_matrix		*sub_matrix;
	unsigned int	j;
	float			det;
	
	if (matrix.rows != matrix.columns)
		error_exit("determinant() error!\n");
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