/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:24:12 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/15 16:44:32 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_closest_min(size_t idx_value, t_list *stack)
{
	size_t	closest;
	t_list	*curr;

	if (!stack)
		return (0);
	if (idx_value < ft_lstmin(stack))
		return (ft_lstmax(stack));
	curr = stack;
	closest = 0;
	while (curr)
	{
		if (curr->index < idx_value && curr->index > closest)
			closest = curr->index;
		curr = curr->next;
	}
	return (closest);
}

size_t	get_closest_max(size_t idx_value, t_list *stack)
{
	size_t	closest;
	t_list	*curr;

	if (!stack)
		return (0);
	if (idx_value > ft_lstmax(stack))
		return (ft_lstmin(stack));
	curr = stack;
	closest = ft_lstmax(stack);
	while (curr)
	{
		if (curr->index > idx_value && curr->index < closest)
			closest = curr->index;
		curr = curr->next;
	}
	return (closest);
}

void	fillcost_a(t_list *a, t_list *b, size_t len_a, size_t len_b)
{
	size_t	tgt_loc;
	size_t	cur_loc;
	t_list	*curr;

	cur_loc = 0;
	curr = a;
	while (curr)
	{
		tgt_loc = get_node_loc(b, get_closest_min(curr->index, b));
		if (tgt_loc <= len_b / 2 && cur_loc <= len_a / 2)
			curr->cost = tgt_loc + cur_loc + 1;
		else if (tgt_loc <= len_b / 2 && cur_loc > len_a / 2)
			curr->cost = tgt_loc + (len_a - cur_loc) + 1;
		else if (tgt_loc > len_b / 2 && cur_loc <= len_a / 2)
			curr->cost = (len_b - tgt_loc) + cur_loc + 1;
		else if (tgt_loc > len_b / 2 && cur_loc > len_a / 2)
			curr->cost = (len_b - tgt_loc) + (len_a - cur_loc) + 1;
		cur_loc++;
		curr = curr->next;
	}
}

void	fillcost_b(t_list *b, t_list *a, size_t len_b, size_t len_a)
{
	size_t	tgt_loc;
	size_t	cur_loc;
	t_list	*curr;

	cur_loc = 0;
	curr = b;
	while (curr)
	{
		tgt_loc = get_node_loc(a, get_closest_max(curr->index, a));
		if (tgt_loc <= len_a / 2 && cur_loc <= len_b / 2)
			curr->cost = tgt_loc + cur_loc + 1;
		else if (tgt_loc <= len_a / 2 && cur_loc > len_b / 2)
			curr->cost = tgt_loc + (len_b - cur_loc) + 1;
		else if (tgt_loc > len_a / 2 && cur_loc <= len_b / 2)
			curr->cost = (len_a - tgt_loc) + cur_loc + 1;
		else if (tgt_loc > len_a / 2 && cur_loc > len_b / 2)
			curr->cost = (len_a - tgt_loc) + (len_b - cur_loc) + 1;
		cur_loc++;
		curr = curr->next;
	}
}
