/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:28:55 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/24 22:37:02 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

t_point	ft_point_new(double x, double y);
t_point	ft_point_sum(t_point a, t_point b);
t_point	ft_point_mult(t_point a, t_point b);
double	ft_line_slope(t_point a, t_point b);

#endif