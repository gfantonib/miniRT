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
	if (argc != 5)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_matrix *ma;
	t_matrix *mb;
	ma = create_matrix(atoi(argv[1]), atoi(argv[2]));
	mb = create_matrix(atoi(argv[3]), atoi(argv[4]));
	if (matrix_equal(*ma, *mb))
		printf("OK\n");
	else
		printf("KO\n");
	ft_free_trashman();
	return (0);
}