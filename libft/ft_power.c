/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:58:53 by gfantoni          #+#    #+#             */
/*   Updated: 2024/06/25 22:35:35 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int	h;

	h = nb;
	if (power <= 0)
	{
		if (power == 0)
		{
			return (1);
		}
		return (0);
	}
	return (h * ft_power(h, (power - 1)));
}
