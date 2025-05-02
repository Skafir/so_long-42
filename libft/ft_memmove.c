/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:50:58 by skafir          #+#    #+#             */
/*   Updated: 2024/12/02 11:42:25 by skafir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	x;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		x = (int)n - 1;
		while (x >= 0)
		{
			*(char *)(dest + x) = *(char *)(src + x);
			x--;
		}
	}
	else
	{
		x = 0;
		while (x < (int)n)
		{
			*(char *)(dest + x) = *(char *)(src + x);
			x++;
		}
	}
	return (dest);
}
