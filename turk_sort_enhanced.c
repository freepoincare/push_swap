/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_enhanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:24:06 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 15:55:18 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enhanced_turk(t_list **stk_a, t_list **stk_b, t_instr **instr_list)
{
	size_t	len;
	size_t	count;

	len = ft_lstsize(*stk_a);
	count = 0;
	while (count < len)
	{
		if ((*stk_a)->index < len / 2)
			do_pb(stk_a, stk_b, instr_list);
		else
			do_ra(stk_a, instr_list);
		count++;
	}
	len = ft_lstsize(*stk_b);
	while (len-- > 0)
	{
		if ((*stk_b)->index < len / 2)
		{
			do_pa(stk_b, stk_a, instr_list);
			do_ra(stk_a, instr_list);
		}
		else if ((*stk_b)->index > len / 2)
			do_pa(stk_b, stk_a, instr_list);
	}
	turk_sort(stk_a, stk_b, instr_list);
}

static void	chunk_half(t_list **a, t_list **b, t_instr **i, size_t n)
{
	size_t	pushed;

	pushed = 0;
	while (pushed < n / 2)
	{
		if ((*a)->index < n / 2)
		{
			do_pb(a, b, i);
			pushed++;
		}
		else
			do_ra(a, i);
	}
	while (pushed < (n * 3) / 4)
	{
		if ((*a)->index < (n * 3) / 4)
		{
			do_pb(a, b, i);
			pushed++;
		}
		else
			do_ra(a, i);
	}
	while (pushed-- > 0)
		do_pa(b, a, i);
}

void	enhanced_turk1(t_list **stk_a, t_list **stk_b, t_instr **instr_list)
{
	size_t	len;

	if (is_stack_sorted(*stk_a))
		return ;
	len = ft_lstsize(*stk_a);
	chunk_half(stk_a, stk_b, instr_list, len);
	turk_sort(stk_a, stk_b, instr_list);
}

static void	chunk_stack(t_list **a, t_list **b, t_instr **ins, int n)
{
	size_t	pushed;

	pushed = 0;
	if (ft_lstsize(*a) > 150)
	{
		while (pushed < 150)
		{
			if ((*a)->index < (size_t)150 * n)
			{
				do_pb(a, b, ins);
				pushed++;
			}
			else
				do_ra(a, ins);
		}
	}
}

void	enhanced_turk2(t_list **stk_a, t_list **stk_b, t_instr **instr_list)
{
	size_t	len;
	int		n_chunk;
	int		count;

	if (is_stack_sorted(*stk_a))
		return ;
	len = ft_lstsize(*stk_a);
	n_chunk = len / 150;
	count = n_chunk - 1;
	while (count >= 0)
	{
		chunk_stack(stk_a, stk_b, instr_list, n_chunk - count);
		count--;
	}
	count = ft_lstsize(*stk_b);
	while (count-- > 0)
		do_pa(stk_b, stk_a, instr_list);
	turk_sort(stk_a, stk_b, instr_list);
}
