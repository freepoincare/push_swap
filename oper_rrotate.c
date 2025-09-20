/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:40 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 16:01:23 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_list **head)
{
	t_list	*prev;
	t_list	*curr;

	if (!head || !(*head) || !(*head)->next)
		return ;
	prev = NULL;
	curr = *head;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *head;
	*head = curr;
}

void	do_rra(t_list **stack_a, t_instr **instr_list)
{
	rrotate(stack_a);
	add_instruction(instr_list, rra);
}

void	do_rrb(t_list **stack_b, t_instr **instr_list)
{
	rrotate(stack_b);
	add_instruction(instr_list, rrb);
}

void	do_rrr(t_list **stack_a, t_list **stack_b, t_instr **instr_list)
{
	rrotate(stack_a);
	rrotate(stack_b);
	add_instruction(instr_list, rrr);
}
