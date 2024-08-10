/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:26:31 by gfantoni          #+#    #+#             */
/*   Updated: 2024/08/10 13:40:43 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
#define TUPLE_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w;
	
} t_tuple;

t_tuple* create_point(float x, float y, float z);

#endif