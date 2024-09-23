/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 18:48:10 by gfantoni         ###   ########.fr       */
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
			if (matrix.matrix[i][j] < 0)
				matrix.matrix[i][j] = -(matrix.matrix[i][j]);
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

int main(int argc, char *argv[])
{
	t_matrix	*transform;
	t_matrix	*point;
	t_matrix	*point_new;
	char		**values;
	
	if (argc != 2)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	values = ft_split(argv[1], ' ');
	ft_collect_mem(values);
	point = create_point(atof(values[0]), atof(values[1]), atof(values[2]));
	transform = rotate_x(PI / 4);
	point_new = matrix_matrix_mult(*transform, *point);
	print_matrix(*point);
	printf("\n");
	print_matrix(*point_new);
	ft_free_trashman();
	return (0);
}