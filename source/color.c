/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:31:52 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/23 12:04:01 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "error_exit.h"

t_matrix* create_color(float red, float green, float blue)
{
	t_matrix *color;

	color = create_matrix(3, 1);
	color->matrix[0][0] = red;
	color->matrix[1][0] = green;
	color->matrix[2][0] = blue;
	return (color);
}

t_matrix* color_color_mult(t_matrix color_a, t_matrix color_b)
{
	t_matrix *result_color;

	if (color_a.columns != 1 || color_b.columns != 1)
		error_exit("color_color_mult() error: both arguments must be vertical vectors\n");
	if (color_a.rows != 3 || color_b.rows != 3)
		error_exit("color_color_mult() error: both arguments must have three rows\n");
	result_color = create_color(color_a.matrix[0][0] * color_b.matrix[0][0],
		color_a.matrix[1][0] * color_b.matrix[1][0],
		color_a.matrix[2][0] * color_b.matrix[2][0]);
	return (result_color);
}