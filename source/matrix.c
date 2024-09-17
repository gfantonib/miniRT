/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:30:58 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 09:19:03 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

float **create_matrix(unsigned int row, unsigned int column)
{
	unsigned int i;
	float **matrix;
	
	matrix = (float **)calloc(row, sizeof(float *));
	ft_collect_mem(matrix);
	i = 0;
	while(i < row)
	{
		matrix[i] = (float *)calloc(column, sizeof(float));	
		ft_collect_mem(matrix[i]);
		i++;
	}
	return (matrix);
}