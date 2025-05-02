/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:41:37 by skafir            #+#    #+#             */
/*   Updated: 2025/04/08 08:56:23 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*img[10];
	void	*win;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	int		movement;
	char	**map;
	int		collect;
}			t_vars;

typedef struct s_map
{
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
}			t_map;

void		ft_error(char **map, char *error);

char		**ft_maps(char *file);
void		ft_check_file_extension(char *file_line);
int			find(char *str, char *to_find);
char		**ft_maps(char *file);
void		ft_valid_maps(t_vars *vars);

int			get_height(char **map);
void		check_is_rectangular(t_vars **vars);
int			check_line(char *line);
void		check_surrounded_by_walls(t_vars **v);
void		check_elements(t_vars **vars);

void		ft_images(t_vars *v, int xy[], char *img, int index);
void		ft_image_to_map(char p, int x1, int y1, t_vars **v);

void		to_left(t_vars **v);
void		to_right(t_vars **v);
void		to_up(t_vars **v);
void		to_down(t_vars **v);

int			ft_key_handler(int keycode, t_vars *vars);
int			ft_exit(t_vars *v);
void		ft_exit_door(t_vars ***v);

int			check_path_validity(t_vars *vars);
void		free_map_cpy(char **map);

#endif