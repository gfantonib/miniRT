/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/13 17:32:02 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "matrix.h"
#include <stdio.h>

void print_matrix(float **matrix, int row, int column)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i< row)
	{
		j = 0;
		while(j < column)
		{
			matrix[i][j] = (float)i;
			printf("%f ", matrix[i][j] );
			j++;
		}
		printf("\n");
		i++;
	}	
}
// int argc, char *argv[]
int main()
{	
	float **matrix;

	matrix = create_matrix(3, 4);
	print_matrix(matrix, 3, 4);
	
	return (0);
}