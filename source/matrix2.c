/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:17:57 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/20 12:40:45 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "tuple.h"
#include "error_exit.h"

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