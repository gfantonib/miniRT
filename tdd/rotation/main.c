/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 21:12:09 by gfantoni         ###   ########.fr       */
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
			printf("%f ", matrix.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void fill_matrix(t_matrix *matrix, char **values)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	k = 0;
	while(i < matrix->rows)
	{
		j = 0;
		while(j < matrix->columns)
		{
			matrix->matrix[i][j] = atof(values[k]);
			ft_collect_mem(values[k]);
			j++;
			k++;
		}
		i++;
	}
}

int main()
{
	t_matrix	*transform;
	t_matrix	*point;
	t_matrix	*point_new;
	// char		**values;
	
	// if (argc != 1)
	// {
	// 	printf("TEST ERROR!\n");
	// 	return (1);
	// }
	// values = ft_split(argv[1], ' ');
	// ft_collect_mem(values);

	point = create_point(0, 1, 0);
	transform = rotate_x(PI / 4);
	point_new = matrix_matrix_mult(*transform, *point);
	print_matrix(*point_new);

	point = create_point(0, 0, 1);
	transform = rotate_y(PI / 4);
	point_new = matrix_matrix_mult(*transform, *point);
	printf("\n");
	print_matrix(*point_new);
	
	point = create_point(0, 1, 0);
	transform = rotate_z(PI / 4);
	point_new = matrix_matrix_mult(*transform, *point);
	printf("\n");
	print_matrix(*point_new);
	
	ft_free_trashman();
	return (0);
}