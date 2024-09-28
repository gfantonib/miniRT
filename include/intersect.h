/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:31:59 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/28 12:22:39 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "../libft/libft.h"
// # include "matrix.h"
// # include "ray.h"
// # include "math.h"
// # include "stdlib.h"

enum object_type 
{
  SPHERE = 1,
};

typedef struct s_intersect
{
	int					type;
	float				t_value;
	void				*object;
	struct s_intersect	*next;
}	t_intersect;

t_intersect		*inter_lstnew(int type, void *object, float t_value);
void			inter_lstadd_sorted(t_intersect **lst, t_intersect *new);
t_intersect		*inter_lstlast(t_intersect *lst);
void			inter_lstiter(t_intersect *lst, void (*f)(float));
t_intersect		*hit(t_intersect **head);

#endif