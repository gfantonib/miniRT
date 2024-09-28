/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/28 10:32:34 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../libft/libft.h"
# include "matrix.h"
# include "ray.h"
# include "intersect.h"
// # include "math.h"
// # include "stdlib.h"

typedef struct s_sphere
{
	int			type;
	t_matrix	*center;
}	t_sphere;

t_sphere *create_sphere(t_matrix center);
t_intersect *sphere_intersect(t_sphere *sphere, t_ray ray);
#endif