/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:22:09 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 21:10:41 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *s)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	number = ft_atol(s);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

static long	is_valid_input(char **s)
{
	char	**split;
	int		i;
	long	count;

	count = 0;
	while (*s)
	{
		split = ft_split(*s);
		if (!split)
			return (-1);
		i = 0;
		while (split[i])
		{
			if (!is_valid_number(split[i]))
			{
				ft_freeall(split);
				return (0);
			}
			count++;
			i++;
		}
		ft_freeall(split);
		s++;
	}
	return (count);
}

static int	is_duplicate(int *arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	store_inputs(char **s, int *arr)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	while (*s)
	{
		split = ft_split(*s);
		if (!split)
		{
			ft_freeall(split);
			exit_error();
		}
		i = 0;
		while (split[i])
		{
			arr[j] = (int)ft_atol(split[i]);
			j++;
			i++;
		}
		ft_freeall(split);
		s++;
	}
}

int	*manage_args(char **str, long *size_out)
{
	long	size;
	int		*int_arr;

	size = is_valid_input(str);
	if (size <= 0 || size > UINT_MAX)
		exit_error();
	int_arr = (int *)malloc(sizeof(int) * (size_t)size);
	if (!int_arr)
		exit_error();
	store_inputs(str, int_arr);
	if (is_duplicate(int_arr, (size_t)size))
	{
		free(int_arr);
		exit_error();
	}
	*size_out = size;
	return (int_arr);
}
