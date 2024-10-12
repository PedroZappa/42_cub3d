/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   510_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:44:27 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 11:55:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_check_wall_dir(int step, t_target *target, t_coord side);
static void	ft_get_wall_height(t_ray *ray, t_target *target);
static void	ft_get_tile_offset(t_ray ray, t_target *target, t_tex tex);

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
		if (ft_map_at(cub->map, cub->ray->map) != '0')
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
	if ((target->wall_dir == NORTH) || (target->wall_dir == SOUTH))
		target->dist = ray->small_delta->y - ray->delta_dist->y;
	else
		target->dist = ray->small_delta->x - ray->delta_dist->x;
	if (target->dist == 0)
		target->wall_height = WINDOW_H;
	else
		target->wall_height = (WINDOW_H / target->dist);
	target->wall_top = (target->wall_height / 2) + (WINDOW_H / 2);
	if (target->wall_height >= WINDOW_H)
		target->wall_height = (WINDOW_H - 1);
	target->wall_bottom = ((-target->wall_height / 2) + (WINDOW_H / 2));
	if (target->wall_bottom < 0)
		target->wall_bottom = 0;
}

static void	ft_get_tile_offset(t_ray ray, t_target *target, t_tex tex)
{
	if ((target->wall_dir == NORTH) || (target->wall_dir == SOUTH))
		target->hitpoint = ray.pos->y + target->dist * ray.ray_dir->y;
	else
		target->hitpoint = ray.pos->x + target->dist * ray.ray_dir->x;
	target->tile_offset = target->hitpoint - floor(target->hitpoint);
	target->tex = (target->tile_offset * (double)tex.width);
	if (((target->wall_dir == NORTH) || ((target->wall_dir == SOUTH) \
			&& (ray.ray_dir->y < 0))) || ((target->wall_dir == WEST) \
		|| ((target->wall_dir == EAST) && (target->wall_dir > 0))))
		target->tex_x = (tex.width - target->tex - 1);
}
