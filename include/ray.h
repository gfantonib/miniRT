/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/27 09:18:14 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../libft/libft.h"
# include "matrix.h"
// # include "math.h"
// # include "stdlib.h"

typedef struct s_ray
{
	t_matrix	*origin;
	t_matrix	*direction;
}	t_ray;

t_matrix	*position(t_ray ray, float t);

#endif