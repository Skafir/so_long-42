/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:29:47 by skafir          #+#    #+#             */
/*   Updated: 2025/04/08 08:56:05 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collected(t_vars ***v)
{
	(**v)->collect--;
	(**v)->map[((**v)->y_p / 64)][((**v)->x_p / 64)] = '0';
	ft_image_to_map('0', (**v)->x_p, (**v)->y_p, *v);
}

void	to_left(t_vars **v)
{
	char	*moov;

	ft_image_to_map('0', (*v)->x_p, (*v)->y_p, v);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit(*v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] != '1')
	{
		(*v)->x_p -= 64;
		moov = ft_itoa(++(**v).movement);
		ft_putstr_fd(moov, 1);
		write(1, "\n", 1);
		free(moov);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	ft_image_to_map('P', (*v)->x_p, (*v)->y_p, v);
}

void	to_right(t_vars **v)
{
	char	*moov;

	ft_image_to_map('0', (*v)->x_p, (*v)->y_p, v);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit(*v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] != '1')
	{
		(*v)->x_p += 64;
		moov = ft_itoa(++(**v).movement);
		ft_putstr_fd(moov, 1);
		write(1, "\n", 1);
		free(moov);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	ft_image_to_map('P', (*v)->x_p, (*v)->y_p, v);
}

void	to_up(t_vars **v)
{
	char	*moov;

	ft_image_to_map('0', (*v)->x_p, (*v)->y_p, v);
	if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit(*v);
	}
	else if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p -= 64;
		moov = ft_itoa(++(**v).movement);
		ft_putstr_fd(moov, 1);
		write(1, "\n", 1);
		free(moov);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	ft_image_to_map('P', (*v)->x_p, (*v)->y_p, v);
}

void	to_down(t_vars **v)
{
	char	*moov;

	ft_image_to_map('0', (*v)->x_p, (*v)->y_p, v);
	if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			ft_exit(*v);
	}
	else if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p += 64;
		moov = ft_itoa(++(**v).movement);
		ft_putstr_fd(moov, 1);
		write(1, "\n", 1);
		free(moov);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	ft_image_to_map('P', (*v)->x_p, (*v)->y_p, v);
}
