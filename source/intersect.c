/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:51:48 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/28 10:28:02 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

t_intersect	*inter_lstnew(int type, void *object, float t_value)
{
	t_intersect	*new_node;

	new_node = malloc(sizeof(t_intersect));
	if (new_node == NULL)
		return (NULL);
	new_node->type = type;
	new_node->object = object;
	new_node->t_value = t_value;
	new_node->next = NULL;
	return (new_node);
}

void	inter_lstadd_back(t_intersect **lst, t_intersect *new)
{
	t_intersect	*last_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = inter_lstlast(*lst);
	last_node->next = new;
}

t_intersect	*inter_lstlast(t_intersect *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	inter_lstiter(t_intersect *lst, void (*f)(float))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->t_value);
		lst = lst->next;
	}
}