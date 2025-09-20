/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:58 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 15:55:48 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_cheapest_node_val_atob(t_list *stka, t_list *stkb)
{
	size_t	len_a;
	size_t	len_b;
	size_t	value;
	t_list	*curr;

	if (!stka || !stkb)
		return (0);
	len_a = ft_lstsize(stka);
	len_b = ft_lstsize(stkb);
	fillcost_a(stka, stkb, len_a, len_b);
	value = ft_lstmax(stka);
	curr = stka;
	while (curr)
	{
		if (curr->cost == ft_lstmincost(stka) && curr->index < value)
			value = curr->index;
		curr = curr->next;
	}
	return (value);
}

static size_t	get_cheapest_node_val_btoa(t_list *stkb, t_list *stka)
{
	size_t	len_a;
	size_t	len_b;
	size_t	value;
	t_list	*curr;

	if (!stka || !stkb)
		return (0);
	len_a = ft_lstsize(stka);
	len_b = ft_lstsize(stkb);
	fillcost_b(stkb, stka, len_b, len_a);
	value = ft_lstmin(stkb);
	curr = stkb;
	while (curr)
	{
		if (curr->cost == ft_lstmincost(stkb) && curr->index > value)
			value = curr->index;
		curr = curr->next;
	}
	return (value);
}

static void	push_all_atob(t_list **stk_a, t_list **stk_b, t_instr **instr)
{
	size_t	len;
	size_t	cheapest_node_val;
	size_t	target_val;

	len = ft_lstsize(*stk_a);
	while (len > 3 && !is_stack_circularly_sorted(*stk_a))
	{
		cheapest_node_val = get_cheapest_node_val_atob(*stk_a, *stk_b);
		target_val = get_closest_min(cheapest_node_val, *stk_b);
		mov_node_to_top(stk_a, 'A', cheapest_node_val, instr);
		mov_node_to_top(stk_b, 'B', target_val, instr);
		do_pb(stk_a, stk_b, instr);
		len--;
	}
}

void	push_back_btoa(t_list **stk_b, t_list **stk_a, t_instr **instr)
{
	size_t	len;
	size_t	cheapest_node_val;
	size_t	target_val;

	len = ft_lstsize(*stk_b);
	while (len-- > 0)
	{
		cheapest_node_val = get_cheapest_node_val_btoa(*stk_b, *stk_a);
		target_val = get_closest_max(cheapest_node_val, *stk_a);
		mov_node_to_top(stk_b, 'B', cheapest_node_val, instr);
		mov_node_to_top(stk_a, 'A', target_val, instr);
		do_pa(stk_b, stk_a, instr);
	}
}

void	turk_sort(t_list **stk_a, t_list **stk_b, t_instr **instr_list)
{
	size_t	len;

	if (is_stack_sorted(*stk_a))
		return ;
	len = ft_lstsize(*stk_a);
	if (len >= 5 && ft_lstsize(*stk_b) == 2)
	{
		do_pb(stk_a, stk_b, instr_list);
		do_pb(stk_a, stk_b, instr_list);
	}
	push_all_atob(stk_a, stk_b, instr_list);
	if (ft_lstsize(*stk_a) == 3)
		sort_three(stk_a, instr_list);
	push_back_btoa(stk_b, stk_a, instr_list);
	bring_min_to_top(stk_a, instr_list);
}
