/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 09:19:37 by gfantoni         ###   ########.fr       */
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
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	float **matrix;
	matrix = create_matrix(atoi(argv[1]), atoi(argv[2]));
	print_matrix(matrix, atoi(argv[1]), atoi(argv[2]));
	ft_free_trashman();
	return (0);
}