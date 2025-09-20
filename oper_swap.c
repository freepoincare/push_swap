/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:53 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 14:22:54 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	do_sa(t_list **stack_a, t_instr **instr_list)
{
	swap(stack_a);
	add_instruction(instr_list, sa);
}

void	do_sb(t_list **stack_b, t_instr **instr_list)
{
	swap(stack_b);
	add_instruction(instr_list, sb);
}

void	do_ss(t_list **stack_a, t_list **stack_b, t_instr **instr_list)
{
	swap(stack_a);
	swap(stack_b);
	add_instruction(instr_list, ss);
}
