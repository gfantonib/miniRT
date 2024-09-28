/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:51:48 by gfantoni          #+#    #+#             */
/*   Updated: 2024/09/28 12:22:06 by gfantoni         ###   ########.fr       */
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

void inter_lstadd_sorted(t_intersect **lst, t_intersect *new)
{
	if (*lst == NULL || new->t_value < (*lst)->t_value)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		t_intersect *current = *lst;
		while (current->next != NULL && current->next->t_value < new->t_value)
		{
			current = current->next;
		}
		new->next = current->next;
		current->next = new;
	}
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

t_intersect *hit(t_intersect **head)
{
	t_intersect *current;

	current = *head;
	while (current)
	{
		if (current->t_value >= 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
