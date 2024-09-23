/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 10:54:01 by gfantoni         ###   ########.fr       */
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
	t_matrix	*ma;
	char		**ma_values;
	t_matrix	*mc;
	
	if (argc != 6)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	ma = create_matrix(atoi(argv[1]), atoi(argv[2]));
	ma_values = ft_split(argv[3], ' ');
	fill_matrix(ma, ma_values);
	ft_collect_mem(ma_values);
	mc = submatrix(*ma, atoi(argv[4]), atoi(argv[5]));
	print_matrix(*mc);
	ft_free_trashman();
	return (0);
}