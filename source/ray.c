/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:17:51 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/27 09:18:10 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ray.h"

t_matrix	*position(t_ray ray, float t)
{
	return(matrix_add(*ray.origin, *matrix_scalar_mult(*ray.direction, t)));
}