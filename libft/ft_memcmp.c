/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:11:28 by gfantoni          #+#    #+#             */
/*   Updated: 2023/08/10 09:33:14 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*alts1;
	unsigned char	*alts2;
	size_t			i;

	alts1 = (unsigned char *)s1;
	alts2 = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (alts1[i] != alts2[i])
			return (alts1[i] - alts2[i]);
		i++;
	}
	return (0);
}
