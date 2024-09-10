/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:51:28 by gfantoni          #+#    #+#             */
/*   Updated: 2024/06/25 22:35:25 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_sqrt(long nb, long kick)
{
	long	result;

	if (nb > 0)
	{
		while (1)
		{
			result = (kick + (nb / kick)) / 2;
			if (result == kick)
			{
				if (result * result == nb)
					return (result);
				else
					return (0);
			}
			kick = result;
		}
	}
	return (0);
}
