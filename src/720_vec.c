/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   720_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:53 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:24:53 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_vec	*ft_vec_new(double x, double y, double z)
{
	t_vec	*ret;

	ret = malloc(sizeof(t_vec));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_vec	*ft_vec_copy(t_vec *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_vec_new(point->x, point->y, point->z));
}

t_vec	*ft_vec_dir(t_dir dir)
{
	if (dir == NORTH)
		return (ft_vec_new(0, -1, 0));
	if (dir == SOUTH)
		return (ft_vec_new(0, 1, 0));
	if (dir == WEST)
		return (ft_vec_new(-1, 0, 0));
	if (dir == EAST)
		return (ft_vec_new(1, 0, 0));
	return (NULL);
}
