/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/09 17:54:43 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(int argc, char *argv[])
{	
	if (argc != 4)
	{
		printf("TEST ERROR!\n");
		return (1);
	}
	t_tuple *a = create_vector(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	float mag = magnitude(*a);
	printf("%f\n", roundf(mag));
	ft_free_trashman();;
	return (0);
}