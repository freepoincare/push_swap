/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:20:13 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 21:06:36 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

static t_op	convert_str_to_oper(char *str_oper)
{
	if (!ft_strcmp(str_oper, "sa"))
		return (sa);
	else if (!ft_strcmp(str_oper, "sb"))
		return (sb);
	else if (!ft_strcmp(str_oper, "ss"))
		return (ss);
	else if (!ft_strcmp(str_oper, "pa"))
		return (pa);
	else if (!ft_strcmp(str_oper, "pb"))
		return (pb);
	else if (!ft_strcmp(str_oper, "ra"))
		return (ra);
	else if (!ft_strcmp(str_oper, "rb"))
		return (rb);
	else if (!ft_strcmp(str_oper, "rr"))
		return (rr);
	else if (!ft_strcmp(str_oper, "rra"))
		return (rra);
	else if (!ft_strcmp(str_oper, "rrb"))
		return (rrb);
	else if (!ft_strcmp(str_oper, "rrr"))
		return (rrr);
	else
		return (invalid_op);
}

static void	do_operation(t_list **a, t_list **b, t_op oper, t_instr **instr)
{
	if (oper == sa)
		do_sa(a, instr);
	else if (oper == sb)
		do_sb(b, instr);
	else if (oper == ss)
		do_ss(a, b, instr);
	else if (oper == pa)
		do_pa(b, a, instr);
	else if (oper == pb)
		do_pb(a, b, instr);
	else if (oper == ra)
		do_ra(a, instr);
	else if (oper == rb)
		do_rb(b, instr);
	else if (oper == rr)
		do_rr(a, b, instr);
	else if (oper == rra)
		do_rra(a, instr);
	else if (oper == rrb)
		do_rrb(b, instr);
	else if (oper == rrr)
		do_rrr(a, b, instr);
	else
		exit_error();
}

static void	run_checker(t_list **stk_a, t_list **stk_b, t_instr **instr)
{
	char	*next_line;
	char	*newlinechar;
	t_op	oper;

	oper = 0;
	next_line = get_next_line(0);
	while (next_line != NULL)
	{
		newlinechar = ft_strchr(next_line, '\n');
		if (newlinechar)
			*newlinechar = '\0';
		oper = convert_str_to_oper(next_line);
		do_operation(stk_a, stk_b, oper, instr);
		free(next_line);
		next_line = get_next_line(0);
	}
	if (is_stack_sorted(*stk_a) && *stk_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		*int_arr;
	long	size;
	t_list	*stack_a;
	t_list	*stack_b;
	t_instr	*instr_list;

	if (ac <= 1)
		return (0);
	stack_b = NULL;
	instr_list = NULL;
	int_arr = manage_args(av + 1, &size);
	stack_a = build_stack(int_arr, (size_t)size);
	if (!stack_a)
	{
		free(int_arr);
		exit_error();
	}
	run_checker(&stack_a, &stack_b, &instr_list);
	free(int_arr);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
