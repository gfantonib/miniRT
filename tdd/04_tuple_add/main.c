/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 16:11:35 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(void)
{	
	t_tuple *point1 = create_point(1.5, 2.5, 3.5);
	t_tuple *point2 = create_point(1.5, 2.5, 3.5);
	if (tuple_equal(*point1, *point2))
		printf("OK\n");
	else
		printf("KO\n");
		
	t_tuple *point3 = create_point(1.5, 2.5, 3.00005);
	t_tuple *point4 = create_point(1.5, 2.5, 3.00006);
	if (tuple_equal(*point3, *point4))
		printf("KO\n");
	else
		printf("OK\n");

	t_tuple *point5 = create_point(1.5, 2.5, 3.000005);
	t_tuple *point6 = create_point(1.5, 2.5, 3.000006);
	if (tuple_equal(*point5, *point6))
		printf("OK\n");
	else
		printf("KO\n");

	t_tuple *point7 = create_point(1.5, 2.5, 3.5);
	t_tuple *point8 = create_vector(1.5, 2.5, 3.5);
	if (tuple_equal(*point7, *point8))
		printf("KO\n");
	else
		printf("OK\n");
		
	return (0);
}