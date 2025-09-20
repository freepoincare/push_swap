/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:26 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 14:22:27 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!from || !(*from))
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	do_pb(t_list **stack_a, t_list **stack_b, t_instr **instr_list)
{
	push(stack_a, stack_b);
	add_instruction(instr_list, pb);
}

void	do_pa(t_list **stack_b, t_list **stack_a, t_instr **instr_list)
{
	push(stack_b, stack_a);
	add_instruction(instr_list, pa);
}
