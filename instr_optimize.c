/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_optimize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:21:05 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 16:04:25 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_opposite(t_instr *instr1, t_instr *instr2)
{
	if (!instr1 || !instr2)
		return (-1);
	if ((instr1->op == pb && instr2->op == pa) \
		|| (instr1->op == pa && instr2->op == pb) \
		|| (instr1->op == ra && instr2->op == rra) \
		|| (instr1->op == rra && instr2->op == ra) \
		|| (instr1->op == rb && instr2->op == rrb) \
		|| (instr1->op == rrb && instr2->op == rb))
	{
		return (1);
	}
	return (0);
}

static int	is_mergeable(t_instr *instr1, t_instr *instr2)
{
	if (!instr1 || !instr2)
		return (-1);
	if ((instr1->op == sa && instr2->op == sb) \
		|| (instr1->op == sb && instr2->op == sa))
		return (MERGE_SA_SB);
	else if ((instr1->op == ra && instr2->op == rb) \
		|| (instr1->op == rb && instr2->op == ra))
		return (MERGE_RA_RB);
	else if ((instr1->op == rra && instr2->op == rrb) \
		|| (instr1->op == rrb && instr2->op == rra))
		return (MERGE_RRA_RRB);
	return (0);
}

static void	remove_opposite_pair(t_instr **instr_list, t_instr *curr)
{
	t_instr	*temp;

	if (curr == *instr_list)
	{
		temp = curr->next->next;
		*instr_list = temp;
	}
	else
	{
		temp = *instr_list;
		while (temp->next != curr)
			temp = temp->next;
		temp->next = curr->next->next;
	}
	free(curr->next);
	free(curr);
}

void	offset_instructions(t_instr **instr_list)
{
	t_instr	*curr;

	if (!instr_list || !(*instr_list))
		return ;
	curr = *instr_list;
	while (curr && curr->next)
	{
		if (is_opposite(curr, curr->next))
		{
			remove_opposite_pair(instr_list, curr);
			curr = *instr_list;
		}
		else
			curr = curr->next;
	}
}

void	merge_instructions(t_instr **instr_list)
{
	t_instr	*curr;
	t_instr	*temp;
	int		merge_type;

	if (!instr_list || !(*instr_list))
		return ;
	curr = *instr_list;
	while (curr && curr->next)
	{
		merge_type = is_mergeable(curr, curr->next);
		if (merge_type >= 1)
		{
			if (merge_type == MERGE_SA_SB)
				curr->op = ss;
			else if (merge_type == MERGE_RA_RB)
				curr->op = rr;
			else if (merge_type == MERGE_RRA_RRB)
				curr->op = rrr;
			temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}
		curr = curr->next;
	}
}
