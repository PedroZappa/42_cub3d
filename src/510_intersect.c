/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   510_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:44:27 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 11:22:41 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_check_wall_dir(int step, t_target *target, t_coord side);
static void	ft_get_wall_height(t_ray *ray, t_target *target);
static void	ft_get_tile_offset(t_ray ray, t_target *target, t_tex tex);
static bool	ft_gottahit(t_point *point, t_cub *cub);

void	ft_get_intersection(t_cub *cub, t_target *target)
{
	while (true)
	{
		if (cub->ray->small_delta->x < cub->ray->small_delta->y)
		{
			cub->ray->small_delta->x += cub->ray->delta_dist->x;
			cub->ray->map->x += cub->ray->step->x;
			ft_check_wall_dir(cub->ray->step->x, target, X);
		}
		else
		{
			cub->ray->small_delta->y += cub->ray->delta_dist->y;
			cub->ray->map->y += cub->ray->step->y;
			ft_check_wall_dir(cub->ray->step->y, target, Y);
		}
		if (ft_gottahit(cub->ray->map, cub))
			break ;
	}
	ft_get_wall_height(cub->ray, target);
	ft_get_tile_offset(*cub->ray, target, cub->map->tex[target->wall_dir]);
}

static void	ft_check_wall_dir(int step, t_target *target, t_coord side)
{
	if (side == X)
	{
		if (step == 1)
			target->wall_dir = EAST;
		else if (step == -1)
			target->wall_dir = WEST;
	}
	else if (side == Y)
	{
		if (step == 1)
			target->wall_dir = NORTH;
		else if (step == -1)
			target->wall_dir = SOUTH;
	}
}

static void	ft_get_wall_height(t_ray *ray, t_target *target)
{
	(void)ray;
	(void)target;
}

static void	ft_get_tile_offset(t_ray ray, t_target *target, t_tex tex)
{
	(void)ray;
	(void)target;
	(void)tex;
}

static bool	ft_gottahit(t_point *point, t_cub *cub)
{
	(void)point;
	(void)cub;
}
