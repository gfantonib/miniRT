/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:26:31 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/12 10:44:52 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
#define TUPLE_H

#include "../library/libft.h"
#include "stdlib.h"
#include "math.h"

#define EPSILON 0.00001

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w;
	
} t_tuple;

t_tuple*	create_point(float x, float y, float z);
t_tuple*	create_vector(float x, float y, float z);
int			float_equal(float a, float b);
int			tuple_equal(t_tuple a, t_tuple b);
t_tuple*	tuple_add(t_tuple a, t_tuple b);
t_tuple*	tuple_minus(t_tuple a, t_tuple b);

#endif