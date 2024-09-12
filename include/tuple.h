/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:26:31 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/12 13:56:24 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "../libft/libft.h"
# include "math.h"
# include "stdlib.h"

# define EPSILON 0.00001

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w;
}			t_tuple;

enum tuple_type 
{
  VECTOR = 0,
  POINT = 1,
  COLOR = 2
};

t_tuple		*create_point(float x, float y, float z);
t_tuple		*create_vector(float x, float y, float z);
t_tuple		*create_color(float red, float green, float blue);
int			float_equal(float a, float b);
int			tuple_equal(t_tuple a, t_tuple b);
t_tuple		tuple_add(t_tuple a, t_tuple b);
t_tuple		tuple_minus(t_tuple a, t_tuple b);
t_tuple		tuple_neg(t_tuple a);
t_tuple		tuple_scalar_mult(t_tuple a, float b);
t_tuple		tuple_scalar_div(t_tuple a, float b);
float		magnitude(t_tuple vector);
t_tuple		normalize(t_tuple vector);
float		dot_prod(t_tuple vec_a, t_tuple vec_b);
t_tuple		cross_prod(t_tuple vec_a, t_tuple vec_b);
t_tuple		color_color_mult(t_tuple a, t_tuple b);

#endif