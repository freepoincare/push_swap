/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:39 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 15:43:25 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rra_sa(t_list **stack_a, t_instr **instr_list)
{
	do_rra(stack_a, instr_list);
	do_sa(stack_a, instr_list);
}

static void	do_ra_sa(t_list **stack_a, t_instr **instr_list)
{
	do_ra(stack_a, instr_list);
	do_sa(stack_a, instr_list);
}

void	sort_three(t_list **stack_a, t_instr **instr_list)
{
	int		arr[3];
	int		i;
	t_list	*curr;

	curr = *stack_a;
	i = 0;
	while (i < 3 && curr)
	{
		arr[i++] = curr->index;
		curr = curr->next;
	}
	if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		return ;
	else if (arr[0] < arr[1] && arr[0] < arr[2] && arr[1] > arr[2])
		do_rra_sa(stack_a, instr_list);
	else if (arr[0] > arr[1] && arr[0] < arr[2] && arr[1] < arr[2])
		do_sa(stack_a, instr_list);
	else if (arr[0] < arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		do_rra(stack_a, instr_list);
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		do_ra(stack_a, instr_list);
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
		do_ra_sa(stack_a, instr_list);
}

void	sort_small_stack(t_list **sta, t_list **stb, t_instr **inst, int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && !is_stack_sorted(*sta))
		do_sa(sta, inst);
	else if (size == 3)
		sort_three(sta, inst);
	else
	{
		bring_min_to_top(sta, inst);
		do_pb(sta, stb, inst);
		sort_small_stack(sta, stb, inst, size - 1);
		do_pa(stb, sta, inst);
	}
}

void	sort_small_medium_inversed_stack(t_list **stack_a)
{
	t_list	*stack_b;
	t_instr	*instr;
	long	size;

	if (is_stack_sorted(*stack_a))
		return ;
	stack_b = NULL;
	instr = NULL;
	size = (long)ft_lstsize(*stack_a);
	if ((size >= 2 && size <= 5) || is_stack_inversely_sorted(*stack_a))
		sort_small_stack(stack_a, &stack_b, &instr, (int)size);
	else if (size > 5 && size < 250)
		turk_sort(stack_a, &stack_b, &instr);
	offset_instructions(&instr);
	merge_instructions(&instr);
	print_instructions(instr);
	free_instructions(instr);
}
