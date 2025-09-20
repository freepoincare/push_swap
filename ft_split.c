/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:20:53 by eunkim            #+#    #+#             */
/*   Updated: 2025/05/14 16:05:36 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	is_print(char c)
{
	return (c >= 33 && c <= 126);
}

static int	count_words(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (is_print(s[i]) && (s[i + 1] == '\0' || is_space(s[i + 1])))
			count++;
		i++;
	}
	return (count);
}

static void	split_string(char **split, char *s, size_t w_count)
{
	size_t	i;
	size_t	j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	while (s[i] && j < w_count)
	{
		if ((i == 0 || is_space(s[i - 1])) && is_print(s[i]))
		{
			len = 0;
			while (is_print(s[i + len]))
				len++;
			split[j] = malloc(sizeof(char) * (len + 1));
			if (!split[j])
				ft_freeall_and_exit(split);
			k = 0;
			while (k < len)
				split[j][k++] = s[i++];
			split[j][len] = '\0';
			j++;
		}
		i++;
	}
}

char	**ft_split(char *str)
{
	char	**split;
	size_t	w_count;

	if (!str)
		return (NULL);
	w_count = count_words(str);
	split = malloc(sizeof(char *) * (w_count + 1));
	if (!split)
		return (NULL);
	split[w_count] = NULL;
	split_string(split, str, w_count);
	return (split);
}
