/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:12:03 by eunkim            #+#    #+#             */
/*   Updated: 2025/03/11 17:29:06 by eunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_remainder(char *line)
{
	char	*remainder;
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	if (line[len] == '\0' || line[1] == '\0')
		return (NULL);
	remainder = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[len + 1] = '\0';
	return (remainder);
}

static char	*read_line(int fd, char *buffer, char *reserve)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!reserve)
			reserve = ft_strdup("");
		tmp = reserve;
		reserve = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(reserve, '\n'))
			break ;
	}
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, reserve);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	reserve = get_remainder(line);
	return (line);
}
