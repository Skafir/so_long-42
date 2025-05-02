/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:03:58 by skafir          #+#    #+#             */
/*   Updated: 2025/04/07 11:42:22 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **map, char *error)
{
	int	x;

	if (map)
	{
		x = 0;
		while (map[x])
		{
			free(map[x]);
			x++;
		}
		free(map);
	}
	ft_putstr_fd("\033[1;31mError\n", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("\033[0m\n", 1);
	exit(1);
}

void	ft_valid_maps(t_vars *vars)
{
	check_elements(&vars);
	check_is_rectangular(&vars);
	check_surrounded_by_walls(&vars);
}

void	render_map(t_vars *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			ft_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 64;
			vars->win_w--;
		}
		vars->win_w = backup_w;
		y_map++;
		y1 += 64;
		vars->win_h--;
	}
}

void	init_size(t_vars *vars)
{
	int	x;

	x = 0;
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
	while (x < 10)
	{
		vars->img[x] = NULL;
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || !argv[1])
	{
		ft_error(NULL, "So long need 2 args.");
		exit(1);
	}
	ft_check_file_extension(argv[1]);
	vars.map = ft_maps(argv[1]);
	if (!vars.map)
		exit(1);
	ft_valid_maps(&vars);
	init_size(&vars);
	if (!check_path_validity(&vars))
		ft_error(vars.map, "Cannot reach all items (collectibles or exit).");
	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(1);
	vars.win = mlx_new_window(vars.mlx, vars.win_w * 64, vars.win_h * 64,
			"So-Long");
	render_map(&vars);
	mlx_hook(vars.win, 2, (1L << 0), ft_key_handler, &vars);
	mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
