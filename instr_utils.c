/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:21:31 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 14:21:33 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	instr_size(t_instr *instr)
{
	size_t	size;

	size = 0;
	while (instr)
	{
		size++;
		instr = instr->next;
	}
	return (size);
}

void	add_instruction(t_instr **instr_list, t_op op)
{
	t_instr	*new;
	t_instr	*curr;

	new = malloc(sizeof(t_instr));
	if (!new)
		return ;
	new->op = op;
	new->next = NULL;
	if (!(*instr_list))
		*instr_list = new;
	else
	{
		curr = *instr_list;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

static void	print_op(t_op op)
{
	if (op == sa)
		write(1, "sa\n", 3);
	else if (op == sb)
		write(1, "sb\n", 3);
	else if (op == ss)
		write(1, "ss\n", 3);
	else if (op == pa)
		write(1, "pa\n", 3);
	else if (op == pb)
		write(1, "pb\n", 3);
	else if (op == ra)
		write(1, "ra\n", 3);
	else if (op == rb)
		write(1, "rb\n", 3);
	else if (op == rr)
		write(1, "rr\n", 3);
	else if (op == rra)
		write(1, "rra\n", 4);
	else if (op == rrb)
		write(1, "rrb\n", 4);
	else if (op == rrr)
		write(1, "rrr\n", 4);
}

void	print_instructions(t_instr *instr_list)
{
	while (instr_list)
	{
		print_op(instr_list->op);
		instr_list = instr_list->next;
	}
}

void	free_instructions(t_instr *instr_list)
{
	t_instr	*temp;

	while (instr_list)
	{
		temp = instr_list->next;
		free(instr_list);
		instr_list = temp;
	}
}
