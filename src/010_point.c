/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:29:46 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/24 22:37:29 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/point.h"

t_point	ft_point_new(double x, double y)
{
	return ((t_point){x, y});
}

t_point	ft_point_sum(t_point a, t_point b)
{
	t_point	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_point	ft_point_mult(t_point a, t_point b)
{
	t_point	ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	return (ret);
}

double	ft_line_slope(t_point a, t_point b)
{
	return ((b.y - a.y) / (b.x - a.x));
}
