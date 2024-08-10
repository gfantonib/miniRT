/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:14:43 by gfantoni          #+#    #+#             */
/*   Updated: 2023/08/10 09:34:33 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*alts;
	size_t	len;

	alts = (char *)s;
	len = ft_strlen(s);
	if (c == '\0')
		return (alts + len);
	while (len != 0)
	{
		if (alts[len] == (char)c)
			return (alts + len);
		len--;
	}
	if (s[0] == (char)c)
		return (alts);
	return (0);
}
