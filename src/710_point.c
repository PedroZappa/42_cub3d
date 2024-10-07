/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   710_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:48 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:24:48 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_point	*ft_point_new(int x, int y)
{
	t_point	*ret;

	ret = malloc(sizeof(t_point));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_point	*ft_point_copy(t_point *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_point_new(point->x, point->y));
}
