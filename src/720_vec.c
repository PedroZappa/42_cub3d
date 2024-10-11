/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   720_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:53 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 21:05:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_vec	*ft_vec_new(double x, double y)
{
	t_vec	*ret;

	ret = malloc(sizeof(t_vec));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_vec	*ft_vec_copy(t_vec *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_vec_new(point->x, point->y));
}

t_vec	*ft_vec_dir(t_dir dir)
{
	if (dir == NORTH)
		return (ft_vec_new(0, -1));
	if (dir == SOUTH)
		return (ft_vec_new(0, 1));
	if (dir == WEST)
		return (ft_vec_new(-1, 0));
	if (dir == EAST)
		return (ft_vec_new(1, 0));
	return (NULL);
}

void	ft_norm_vector(t_vec *vec)
{
	double	len;

	len = sqrt((vec->x * vec->x) + (vec->y * vec->y));
	if (len != 0)
	{
		vec->x /= len;
		vec->y /= len;
	}
}
