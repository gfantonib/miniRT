/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:22:11 by gfantoni          #+#    #+#             */
/*   Updated: 2023/08/10 09:33:23 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*placeholder;

	placeholder = (unsigned char *)s;
	while (n > 0)
	{
		*placeholder = (unsigned char)c;
		placeholder++;
		n--;
	}
	return (s);
}
