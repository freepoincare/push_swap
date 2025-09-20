/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:28 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 14:49:38 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sortvariant0(t_list **a, t_instr **i)
{
	t_list	*b;

	b = NULL;
	enhanced_turk(a, &b, i);
	offset_instructions(i);
	merge_instructions(i);
}

static void	sortvariant1(t_list **a, t_instr **i, int *arr, size_t n)
{
	t_list	*b;

	b = NULL;
	*a = build_stack(arr, n);
	if (!(*a))
		return ;
	enhanced_turk1(a, &b, i);
	offset_instructions(i);
	merge_instructions(i);
}

static void	sortvariant2(t_list **a, t_instr **i, int *arr, size_t n)
{
	t_list	*b;

	b = NULL;
	*a = build_stack(arr, n);
	if (!(*a))
		return ;
	enhanced_turk2(a, &b, i);
	offset_instructions(i);
	merge_instructions(i);
}

static void	print_best_instr(t_instr *inst, t_instr *inst1, t_instr *inst2)
{
	size_t	count;
	size_t	count1;
	size_t	count2;

	count = instr_size(inst);
	count1 = instr_size(inst1);
	count2 = instr_size(inst2);
	if (count <= count1 && count <= count2)
		print_instructions(inst);
	else if (count1 <= count && count1 <= count2)
		print_instructions(inst1);
	else
		print_instructions(inst2);
}

void	sort_big_stack(t_list **stk_a, int *int_arr, size_t size)
{
	t_list	*stk_a_cp1;
	t_list	*stk_a_cp2;
	t_instr	*instr;
	t_instr	*instr1;
	t_instr	*instr2;

	if (is_stack_sorted(*stk_a))
		return ;
	stk_a_cp1 = NULL;
	stk_a_cp2 = NULL;
	instr = NULL;
	instr1 = NULL;
	instr2 = NULL;
	sortvariant0(stk_a, &instr);
	sortvariant1(&stk_a_cp1, &instr1, int_arr, size);
	sortvariant2(&stk_a_cp2, &instr2, int_arr, size);
	print_best_instr(instr, instr1, instr2);
	free_stack(stk_a_cp1);
	free_stack(stk_a_cp2);
	free_instructions(instr);
	free_instructions(instr1);
	free_instructions(instr2);
}
