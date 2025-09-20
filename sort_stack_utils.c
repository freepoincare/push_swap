/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:46 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 15:45:09 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_min_loc(t_list *head)
{
	size_t	min;
	size_t	min_loc;
	t_list	*curr;
	size_t	curr_loc;

	if (!head)
		return (0);
	curr = head;
	min = curr->index;
	min_loc = 0;
	curr_loc = 0;
	while (curr)
	{
		if (curr->index < min)
		{
			min = curr->index;
			min_loc = curr_loc;
		}
		curr = curr->next;
		curr_loc++;
	}
	return (min_loc);
}

void	bring_min_to_top(t_list **stack_a, t_instr **instr)
{
	size_t	min_location;
	size_t	size;

	min_location = get_min_loc(*stack_a);
	size = ft_lstsize(*stack_a);
	if (min_location <= (size - 1) / 2)
	{
		while (min_location-- > 0)
			do_ra(stack_a, instr);
	}
	else
	{
		while (min_location++ < size)
			do_rra(stack_a, instr);
	}
}

size_t	get_node_loc(t_list *head, size_t node_val)
{
	t_list	*curr;
	size_t	node_loc;
	size_t	curr_loc;

	if (!head)
		return (0);
	curr = head;
	node_loc = 0;
	curr_loc = 0;
	while (curr)
	{
		if (curr->index == node_val)
		{
			node_loc = curr_loc;
			break ;
		}
		curr = curr->next;
		curr_loc++;
	}
	return (node_loc);
}

void	mov_node_to_top(t_list **stk, char c, size_t val, t_instr **ins)
{
	size_t	node_loc;
	size_t	size;

	node_loc = get_node_loc(*stk, val);
	size = ft_lstsize(*stk);
	if (node_loc <= (size - 1) / 2)
	{
		while (node_loc-- > 0)
		{
			if (c == 'A')
				do_ra(stk, ins);
			else if (c == 'B')
				do_rb(stk, ins);
		}
	}
	else
	{
		while (node_loc++ < size)
		{
			if (c == 'A')
				do_rra(stk, ins);
			else if (c == 'B')
				do_rrb(stk, ins);
		}
	}
}
