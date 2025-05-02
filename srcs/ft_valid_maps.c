/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:06:21 by skafir          #+#    #+#             */
/*   Updated: 2025/04/07 09:40:06 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_is_rectangular(t_vars **vars)
{
	int	y_map;
	int	x_map;
	int	height;
	int	backup;

	y_map = 0;
	backup = 0;
	height = get_height((*vars)->map);
	while (y_map != height)
	{
		x_map = 0;
		while ((*vars)->map[y_map][x_map] != '\0')
			x_map++;
		y_map++;
		if (backup != 0)
		{
			if (backup != x_map)
				ft_error((*vars)->map, "Map is not rectangular");
		}
		else
			backup = x_map;
	}
}

void	check_surrounded_by_walls(t_vars **v)
{
	int	i;

	if (check_line((*v)->map[0]))
		ft_error((*v)->map, "Map is not surrounded by wall (1)");
	i = get_height((*v)->map) - 1;
	while (i)
	{
		if ((*v)->map[i][0] != '1' || (*v)->map[i][ft_strlen((*v)->map[i])
			- 1] != '1')
			ft_error((*v)->map, "Map is not surrounded by wall (1)");
		i--;
	}
	if (check_line((*v)->map[get_height((*v)->map) - 1]))
		ft_error((*v)->map, "Map is not surrounded by wall (1)");
}

int	check_letters(t_vars **vars, int x, int y)
{
	if ((*vars)->map[y][x] != 'E' && (*vars)->map[y][x] != 'P'
		&& (*vars)->map[y][x] != 'C' && (*vars)->map[y][x] != '0'
		&& (*vars)->map[y][x] != '1' && (*vars)->map[y][x] != '\r')
		return (0);
	return (1);
}

void	check_elements(t_vars **vars)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*vars)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*vars)->map[map.y][map.x] != '\0')
		{
			if ((*vars)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*vars)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*vars)->map[map.y][map.x] == 'C')
				map.c++;
			if (!check_letters(vars, map.x, map.y))
				ft_error((*vars)->map, "Invalid letter from the map.");
			map.x++;
		}
	}
	if (map.c < 1 || map.e != 1 || map.p != 1)
		ft_error((*vars)->map, "Missing or to much elements from the map.");
}
