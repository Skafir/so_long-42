/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:56:56 by skafir          #+#    #+#             */
/*   Updated: 2025/04/08 08:23:48 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_error(char *remainder)
{
	char	*line;

	if (!remainder)
		return (NULL);
	line = ft_strdup(remainder);
	if (!line)
		return (NULL);
	free(remainder);
	return (line);
}

int	find_newline(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char **remainder, int newline_index)
{
	char	*line;
	char	*new_remainder;
	int		x;

	if (!remainder || !*remainder)
		return (NULL);
	line = malloc(newline_index + 2);
	if (!line)
		return (NULL);
	x = 0;
	while (x <= newline_index)
	{
		line[x] = (*remainder)[x];
		x++;
	}
	line[x] = '\0';
	new_remainder = ft_strdup(*remainder + newline_index + 1);
	if (!new_remainder)
	{
		free(line);
		return (NULL);
	}
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}

static char	*read_and_store(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(remainder), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		if (!temp)
			free(temp);
		remainder = temp;
		if (find_newline(remainder) != -1)
			break ;
	}
	free(buffer);
	if (bytes_read == -1)
		return (free(remainder), NULL);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			x;

	x = find_newline(remainder);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder && x != -1)
		return (extract_line(&remainder, x));
	remainder = read_and_store(fd, remainder);
	if (!remainder)
		return (NULL);
	x = find_newline(remainder);
	if (x != -1)
		return (extract_line(&remainder, x));
	if (remainder && *remainder)
	{
		line = get_next_line_error(remainder);
		remainder = NULL;
		return (line);
	}
	free(remainder);
	remainder = NULL;
	return (NULL);
}
