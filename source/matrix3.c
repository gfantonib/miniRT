/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:42:23 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/22 12:52:23 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
// #include "tuple.h"
#include "error_exit.h"
#include "epsilon.h"

t_matrix *matrix_minus(t_matrix ma, t_matrix mb)
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
			mc->matrix[i][j] = ma.matrix[i][j] - mb.matrix[i][j];
			j++;
		}
		i++;
	}
	return (mc);
}

void	matrix_neg(t_matrix *matrix)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->columns)
		{
			matrix->matrix[i][j] = -(matrix->matrix[i][j]);
			j++;
		}
		i++;
	}
}