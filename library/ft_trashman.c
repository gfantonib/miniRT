/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trashman.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:12:41 by gfantoni          #+#    #+#             */
/*   Updated: 2024/06/25 21:25:34 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_get_mem_address(void)
{
	static t_list	*ptr;

	return (&ptr);
}

void	ft_collect_mem(void *content)
{
	ft_lstadd_back(ft_get_mem_address(), ft_lstnew(content));
}

void	ft_free_trashman(t_list **lst_memory)
{
	t_list	*next;

	while (*lst_memory)
	{
		next = (*lst_memory)->next;
		free((*lst_memory)->content);
		free(*lst_memory);
		*lst_memory = next;
	}
	*lst_memory = NULL;
}
