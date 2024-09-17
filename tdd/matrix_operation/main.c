/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 09:53:28 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "matrix.h"
#include <stdio.h>

void print_matrix(t_matrix matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < matrix.rows)
	{
		j = 0;
		while(j < matrix.columns)
		{
			matrix.matrix[i][j] = (float)i;
			printf("%f ", matrix.matrix[i][j] );
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
	t_matrix *matrix;
	matrix = create_matrix(atoi(argv[1]), atoi(argv[2]));
	print_matrix(*matrix);
	ft_free_trashman();
	return (0);
}