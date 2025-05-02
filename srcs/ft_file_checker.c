/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:08:15 by skafir          #+#    #+#             */
/*   Updated: 2025/04/07 09:23:15 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_check_file_extension(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".ber"))
				return ;
		}
		file_line++;
	}
	ft_error(NULL, "Bad file extension");
}

char	**ft_handling_lines(char *all_lines, char *line, int fd)
{
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
	{
		free(all_lines);
		ft_error(NULL, "File is empty");
	}
	return (ft_split(all_lines, '\n'));
}

char	**ft_maps(char *file)
{
	char	*line;
	char	*all_lines;
	char	*temp;
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, "Cannot read file");
	line = "";
	all_lines = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		temp = ft_strjoin(all_lines, line);
		all_lines = temp;
		free(line);
	}
	map = ft_handling_lines(all_lines, line, fd);
	free(all_lines);
	return (map);
}
