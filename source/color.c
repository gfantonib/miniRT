/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:31:52 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/17 15:57:59 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include "error_exit.h"

t_tuple* create_color(float red, float green, float blue)
{
	t_tuple *color;

	color = (t_tuple *)ft_calloc(sizeof(t_tuple), 1);
	ft_collect_mem(color);
	color->x = red;
	color->y = green;
	color->z = blue;
	color->w = COLOR;
	return (color);
}

t_tuple color_color_mult(t_tuple a, t_tuple b)
{
	t_tuple color;

	color.x = a.x * b.x;
	color.y = a.y * b.y;
	color.z = a.z * b.z;
	if (a.w == COLOR && b.w == COLOR)
		color.w = COLOR;
	else
		error_exit("color_color_mult() error!\n");
	return (color);
}