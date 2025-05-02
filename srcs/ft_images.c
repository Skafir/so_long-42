/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:09:09 by skafir          #+#    #+#             */
/*   Updated: 2025/04/08 11:31:23 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_img
{
	int		len;
	int		len_to_find;
	int		len_replace;
	int		pos;
	char	*new;
}			t_img;

void	ft_replace_image(t_img *list_img, char *img, char *replace)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (k < list_img->pos)
	{
		list_img->new[k] = img[k];
		k++;
	}
	j = 0;
	while (j < list_img->len_replace)
		list_img->new[k++] = replace[j++];
	while (img[list_img->pos])
		list_img->new[k++] = img[list_img->pos++];
	list_img->new[k] = '\0';
}

char	*ft_change_name(char *img, char *to_find, char *replace)
{
	t_img	list_img;

	list_img.len = ft_strlen(img);
	list_img.len_to_find = ft_strlen(to_find);
	list_img.len_replace = ft_strlen(replace);
	list_img.pos = 0;
	while (img[list_img.pos] && ft_strncmp(&img[list_img.pos], to_find,
			list_img.len_to_find))
		list_img.pos++;
	if (!img[list_img.pos])
		return (img);
	list_img.new = malloc(list_img.len + list_img.len_replace + 1);
	if (!list_img.new)
		return (NULL);
	ft_replace_image(&list_img, img, replace);
	return (list_img.new);
}

void	ft_images(t_vars *v, int xy[], char *img, int index)
{
	int	img_w;
	int	img_h;

	if (v->img[index] != NULL)
	{
		mlx_put_image_to_window(v->mlx, v->win, v->img[index], xy[0], xy[1]);
		return ;
	}
	v->img[index] = mlx_xpm_file_to_image(v->mlx, img, &img_w, &img_h);
	if (v->img[index] == NULL)
		ft_exit(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img[index], xy[0], xy[1]);
}

void	ft_change_image(t_vars *v, int xy[], char *img, int index)
{
	int		x_index;
	int		y_index;
	char	*second_img;

	x_index = xy[0] / 64;
	y_index = xy[1] / 64;
	if ((x_index + y_index) % 2 == 0)
		ft_images(v, xy, img, index);
	else
	{
		second_img = ft_change_name(img, ".xpm", "2");
		ft_images(v, xy, second_img, index + 1);
		free(second_img);
	}
}

void	ft_image_to_map(char p, int x1, int y1, t_vars **v)
{
	int	xy[2];

	xy[0] = x1;
	xy[1] = y1;
	if (p == '1')
		ft_change_image(*v, xy, "assets/environement/three.xpm", 0);
	else if (p == 'C')
	{
		ft_change_image(*v, xy, "assets/food/water.xpm", 2);
		(*v)->collect++;
	}
	else if (p == 'E')
		ft_change_image(*v, xy, "assets/environement/exit.xpm", 4);
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		ft_change_image(*v, xy, "assets/player/0_player.xpm", 6);
	}
	else
		ft_change_image(*v, xy, "assets/environement/grass.xpm", 8);
}
