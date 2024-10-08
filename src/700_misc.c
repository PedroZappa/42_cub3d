/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   700_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:37 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:24:37 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

long	ft_timestamp(void)
{
	struct timeval	tm;

	if (gettimeofday(&tm, NULL))
		return (-1);
	return ((tm.tv_sec * 1000) + (tm.tv_usec * 0.001));
}

int	ft_check_ext(char *file)
{
	char	*pos;

	pos = ft_strrchr(file, '.');
	if (pos == NULL)
		return (FAILURE);
	return (ft_strncmp(pos, ".cub", 5));
}

int	ft_rgb_to_int(t_rgb rgb)
{
	return (((rgb.r & 0xFF) << 16)
		| ((rgb.g & 0xFF) << 8)
		| (rgb.b & 0xFF));
}
