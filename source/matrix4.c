/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:42:23 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/27 13:14:23 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "error_exit.h"
#include "epsilon.h"

void	normalize(t_matrix *matrix)
{
	float mag;
	unsigned int i;
	unsigned int j;
	
	mag = magnitude(*matrix);
	i = 0;
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->columns)
		{
			matrix->matrix[i][j] = matrix->matrix[i][j] / mag;
			j++;
		}
		i++;
	}
}

void print_matrix(t_matrix matrix)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while(i < matrix.rows)
	{
		j = 0;
		while(j < matrix.columns)
		{
			printf("%f ", matrix.matrix[i][j] );
			j++;
		}
		printf("\n");
		i++;
	}	
}
