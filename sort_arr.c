/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:23:15 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 15:41:01 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr_sort, size_t size)
{
	size_t	i;
	int		tmp;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr_sort[i] > arr_sort[i + 1])
			{
				tmp = arr_sort[i];
				arr_sort[i] = arr_sort[i + 1];
				arr_sort[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	*sort_arr(int *arr, size_t size)
{
	int		*sorted;
	size_t	i;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	bubble_sort(sorted, size);
	return (sorted);
}

int	is_sorted_arr(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
