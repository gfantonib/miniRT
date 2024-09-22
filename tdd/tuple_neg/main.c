/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/22 12:56:49 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "matrix.h"

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
	if (argc != 4)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_matrix *a = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	matrix_neg(a);
	print_matrix(*a);
	ft_free_trashman();
	return (0);
}