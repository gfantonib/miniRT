/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:31:01 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 15:38:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

int main(void)
{
	float a = 0.0000001;
	float b = 0.0000002;
	
	if (a == b)
		printf("%f = %f\n", a, b);
	else
		printf("%f != %f\n", a, b);

	if (float_equal(a, b))
		printf("%f = %f\n", a, b);
	else
		printf("%f != %f\n", a, b);
	return (0);
}