/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   110_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:23:16 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 23:26:14 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_point	*ft_point_new(double x, double y, double z)
{
	t_point	*ret;

	ret = malloc(sizeof(t_point));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_point	*ft_point_copy(t_point *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_point_new(point->x, point->y, point->z));
}

t_2dpoint	*ft_2dpoint_new(int x, int y)
{
	t_2dpoint	*ret;

	ret = malloc(sizeof(t_2dpoint));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_2dpoint	*ft_2dpoint_copy(t_2dpoint *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_2dpoint_new(point->x, point->y));
}

t_point	*ft_point_dir(t_dir dir)
{
	if (dir == NORTH)
		return (ft_point_new(0, -1, 0));
	if (dir == SOUTH)
		return (ft_point_new(0, 1, 0));
	if (dir == WEST)
		return (ft_point_new(-1, 0, 0));
	if (dir == EAST)
		return (ft_point_new(1, 0, 0));
	return (NULL);
}
