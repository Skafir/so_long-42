/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:28:27 by skafir          #+#    #+#             */
/*   Updated: 2025/04/08 08:56:08 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_cpy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_destroy_exit(t_vars *v)
{
	mlx_destroy_display(v->mlx);
	free(v->map);
	free(v->mlx);
	exit(1);
}

int	ft_exit(t_vars *v)
{
	int	x;
	int	index;

	index = 0;
	x = 0;
	if (v->map != NULL)
	{
		while (v->map[x] != NULL)
		{
			free(v->map[x]);
			x++;
		}
		while (index < 10)
		{
			if (v->img[index] != NULL)
			{
				mlx_destroy_image(v->mlx, v->img[index]);
				v->img[index] = NULL;
			}
			index++;
		}
		mlx_destroy_window(v->mlx, v->win);
	}
	ft_destroy_exit(v);
	return (0);
}

int	ft_key_handler(int keycode, t_vars *vars)
{
	if (keycode == 100 || keycode == 65363)
		to_right(&vars);
	else if (keycode == 97 || keycode == 65361)
		to_left(&vars);
	else if (keycode == 119 || keycode == 65362)
		to_up(&vars);
	else if (keycode == 115 || keycode == 65364)
		to_down(&vars);
	else if (keycode == 65307)
		ft_exit(vars);
	return (0);
}
