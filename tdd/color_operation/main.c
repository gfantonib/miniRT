/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 10:47:21 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

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

int main(int argc, char *argv[])
{	
	if (argc != 7)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_matrix *color_a = create_color(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	t_matrix *color_b = create_color(atof(argv[4]), atof(argv[5]), atof(argv[6]));
	t_matrix *result_color = color_color_mult(*color_a, *color_b);
	print_matrix(*result_color);
	result_color = matrix_add(*color_a, *color_b);
	print_matrix(*result_color);
	result_color = matrix_minus(*color_a, *color_b);
	print_matrix(*result_color);
	ft_free_trashman();
	return (0);
}