/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:32 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 14:22:34 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*first;
	t_list	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	*head = first->next;
	first->next = NULL;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	do_ra(t_list **stack_a, t_instr **instr_list)
{
	rotate(stack_a);
	add_instruction(instr_list, ra);
}

void	do_rb(t_list **stack_b, t_instr **instr_list)
{
	rotate(stack_b);
	add_instruction(instr_list, rb);
}

void	do_rr(t_list **stack_a, t_list **stack_b, t_instr **instr_list)
{
	rotate(stack_a);
	rotate(stack_b);
	add_instruction(instr_list, rr);
}
