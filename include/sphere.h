/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/27 17:31:09 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../libft/libft.h"
# include "matrix.h"
# include "ray.h"
// # include "math.h"
// # include "stdlib.h"

enum object_type 
{
  SPHERE = 1,
};

typedef struct s_sphere
{
	int			type;
	t_matrix	*center;
}	t_sphere;

t_sphere *create_sphere(t_matrix center);
float	*sphere_intersect(t_sphere sphere, t_ray ray);
#endif