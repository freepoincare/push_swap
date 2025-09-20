/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:20:44 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 16:06:09 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

size_t	ft_lstmax(t_list *lst)
{
	size_t	max;

	if (!lst)
		return (0);
	max = lst->index;
	lst = lst->next;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

size_t	ft_lstmin(t_list *lst)
{
	size_t	min;

	if (!lst)
		return (0);
	min = lst->index;
	lst = lst->next;
	while (lst)
	{
		if (lst->index < min)
			min = lst->index;
		lst = lst->next;
	}
	return (min);
}

size_t	ft_lstmincost(t_list *lst)
{
	size_t	min;

	if (!lst)
		return (0);
	min = lst->cost;
	lst = lst->next;
	while (lst)
	{
		if (lst->cost < min)
			min = lst->cost;
		lst = lst->next;
	}
	return (min);
}

t_list	*ft_lstnew(int value, size_t index)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->cost = 0;
	new_node->next = NULL;
	return (new_node);
}
