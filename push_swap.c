/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:04 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 16:00:56 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*int_arr;
	long	size;
	t_list	*stack_a;

	if (ac <= 1)
		return (0);
	int_arr = manage_args(av + 1, &size);
	stack_a = build_stack(int_arr, (size_t)size);
	if (!stack_a)
	{
		free(int_arr);
		exit_error();
	}
	if (!is_stack_sorted(stack_a))
	{
		if (size < 250 || is_stack_inversely_sorted(stack_a))
			sort_small_medium_inversed_stack(&stack_a);
		else
			sort_big_stack(&stack_a, int_arr, (size_t)size);
	}
	free(int_arr);
	free_stack(stack_a);
	return (0);
}
