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
