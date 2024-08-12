/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:27:34 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/12 14:34:36 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tuple.h"

t_tuple normalize(t_tuple vector)
{
	t_tuple norm_vec;
	float	mag;

	mag = magnitude(vector);
	norm_vec.x = vector.x / mag;
	norm_vec.y = vector.y / mag;
	norm_vec.z = vector.z / mag;
	norm_vec.w = vector.w / mag;
	return (norm_vec);
}