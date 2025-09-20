/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:51 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 15:46:40 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*build_stack_backwards(int *arr, int *sorted, size_t len)
{
	t_list	*stack;
	t_list	*new_node;
	size_t	i;
	size_t	j;

	stack = NULL;
	i = len;
	while (i--)
	{
		j = 0;
		while (j < len && arr[i] != sorted[j])
			j++;
		if (arr[i] == sorted[j])
		{
			new_node = ft_lstnew(arr[i], j);
			if (!new_node)
			{
				free_stack(stack);
				return (NULL);
			}
			new_node->next = stack;
			stack = new_node;
		}
	}
	return (stack);
}

t_list	*build_stack(int *int_arr, size_t size)
{
	t_list	*stack;
	int		*int_arr_sorted;

	int_arr_sorted = sort_arr(int_arr, size);
	if (!int_arr_sorted)
		return (NULL);
	stack = build_stack_backwards(int_arr, int_arr_sorted, size);
	if (!stack)
	{
		free(int_arr_sorted);
		return (NULL);
	}
	free(int_arr_sorted);
	return (stack);
}

int	is_stack_sorted(t_list *stack)
{
	t_list	*curr;

	if (!stack)
		return (1);
	curr = stack;
	while (curr->next)
	{
		if (curr->index > curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_stack_circularly_sorted(t_list *stack)
{
	t_list	*curr;
	size_t	minus_count;
	size_t	plusone_count;
	size_t	size;

	if (!stack || is_stack_sorted(stack))
		return (1);
	curr = stack;
	minus_count = 0;
	plusone_count = 0;
	size = ft_lstsize(stack);
	while (curr->next)
	{
		if ((int)(curr->next->index - curr->index) < 0)
			minus_count++;
		else if ((int)(curr->next->index - curr->index) == 1)
			plusone_count++;
		curr = curr->next;
	}
	if (minus_count <= 1 && plusone_count >= size - 2)
		return (1);
	else
		return (0);
}

int	is_stack_inversely_sorted(t_list *stack)
{
	t_list	*curr;

	if (!stack)
		return (1);
	curr = stack;
	while (curr->next)
	{
		if (curr->index < curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}
