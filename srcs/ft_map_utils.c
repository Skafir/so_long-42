/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:33:59 by skafir          #+#    #+#             */
/*   Updated: 2025/04/07 10:58:12 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   ft_map_utils.c                                                           */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_dim
{
	int		rows;
	int		cols;
}			t_dim;

typedef struct s_dup
{
	int		i;
	int		rows;
	char	**dup;
}			t_dup;

typedef struct s_fp
{
	int		i;
	int		j;
}			t_fp;

typedef struct s_cp
{
	int		valid;
	int		i;
	int		j;
	int		player_x;
	int		player_y;
	char	**mcpy;
}			t_cp;

char	**duplicate_map(char **map)
{
	t_dup	d;

	d.i = 0;
	d.rows = get_height(map);
	d.dup = malloc(sizeof(char *) * (d.rows + 1));
	if (!d.dup)
		return (NULL);
	while (d.i < d.rows)
	{
		d.dup[d.i] = ft_strdup(map[d.i]);
		if (!d.dup[d.i])
		{
			while (d.i--)
				free(d.dup[d.i]);
			free(d.dup);
			return (NULL);
		}
		d.i++;
	}
	d.dup[d.i] = NULL;
	return (d.dup);
}

void	flood_fill(char **map, int x, int y, t_dim dim)
{
	if (x < 0 || x >= dim.rows || y < 0 || y >= dim.cols)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, dim);
	flood_fill(map, x - 1, y, dim);
	flood_fill(map, x, y + 1, dim);
	flood_fill(map, x, y - 1, dim);
}

static void	find_player(char **map, t_dim dim, int *px, int *py)
{
	t_fp	f;

	*px = -1;
	f.i = 0;
	while (f.i < dim.rows)
	{
		f.j = 0;
		while (f.j < dim.cols)
		{
			if (map[f.i][f.j] == 'P')
			{
				*px = f.i;
				*py = f.j;
				return ;
			}
			f.j++;
		}
		f.i++;
	}
}

void	browse_path(t_dim dim, t_cp *cp)
{
	while (cp->i < dim.rows)
	{
		cp->j = 0;
		while (cp->j < dim.cols)
		{
			if (cp->mcpy[cp->i][cp->j] == 'C' || cp->mcpy[cp->i][cp->j] == 'E')
			{
				cp->valid = 0;
				break ;
			}
			cp->j++;
		}
		if (!cp->valid)
			break ;
		cp->i++;
	}
}

int	check_path_validity(t_vars *vars)
{
	t_dim	dim;
	t_cp	cp;

	dim.rows = vars->win_h;
	dim.cols = vars->win_w;
	cp.valid = 1;
	cp.mcpy = duplicate_map(vars->map);
	if (!cp.mcpy)
		ft_error(NULL, "Erreur d'allocation de la map");
	find_player(cp.mcpy, dim, &cp.player_x, &cp.player_y);
	if (cp.player_x == -1)
		ft_error(NULL, "Position du joueur introuvable");
	flood_fill(cp.mcpy, cp.player_x, cp.player_y, dim);
	cp.i = 0;
	browse_path(dim, &cp);
	free_map_cpy(cp.mcpy);
	return (cp.valid);
}
