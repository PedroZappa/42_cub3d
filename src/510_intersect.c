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

static void	ft_check_wall_dir(t_ray *target, t_coord side);
static void	ft_get_wall_height(t_ray *ray);

/**
 * @brief DDA (Digital Differential Analyzer)
 * @param cub a pointer to a t_cub struct
 * @param target Current camera target
 * @details
 * - Compute the intersection between the ray and the map
 * - Compute the wall height
 * - Compute the tile offset
**/
void	ft_get_intersection(t_cub *cub)
{
	while (true)
	{
		if (cub->ray->small_delta->x < cub->ray->small_delta->y)
		{
			cub->ray->small_delta->x += cub->ray->delta_dist->x;
			cub->ray->map->x += cub->ray->step->x;
			ft_check_wall_dir(cub->ray, X);
		}
		else
		{
			cub->ray->small_delta->y += cub->ray->delta_dist->y;
			cub->ray->map->y += cub->ray->step->y;
			ft_check_wall_dir(cub->ray, Y);
		}
		if (ft_map_at_i(cub->map, cub->ray->map->y, cub->ray->map->x) == '1' ||
			ft_map_at_i(cub->map, cub->ray->map->y, cub->ray->map->x) == -1)
			break ;
	}
	ft_get_wall_height(cub->ray);
}

/**
 * @brief Set whioh side of a wall the ray has hit
 * @param step From 1 or -1
 * @param target Current camera target
 * @param side X or Y
**/
static void	ft_check_wall_dir(t_ray *target, t_coord side)
{
	if (side == Y)
	{
		if (target->ray_dir->y > 0)
			target->wall_dir = WEST;
		else
			target->wall_dir = EAST;
	}
	else if (side == X)
	{
		if (target->ray_dir->x > 0)
			target->wall_dir = NORTH;
		else
			target->wall_dir = SOUTH;
	}
}

/**
 * @brief Computes the wall height
 * @param ray A pointer to a t_ray struct
 * @param target Current camera target
 * @details
 * - Get perpendicular distance to wall
 * - Compute the wall height
 * - Get top and bottom coordinates of the wall
**/
static void	ft_get_wall_height(t_ray *ray)
{
	if (ray->wall_dir > SOUTH)
		ray->dist = ray->small_delta->y - ray->delta_dist->y;
	else
		ray->dist = ray->small_delta->x - ray->delta_dist->x;
	if (ray->dist == 0)
		ray->wall_height = WINDOW_H;
	else
		ray->wall_height = (WINDOW_H / ray->dist);
	ray->wall_top = (ray->wall_height / 2) + (WINDOW_H / 2);
	if (ray->wall_top >= WINDOW_H)
		ray->wall_top = (WINDOW_H - 1);
	ray->wall_bottom = ((-ray->wall_height / 2) + (WINDOW_H / 2));
	if (ray->wall_bottom < 0)
		ray->wall_bottom = 0;
}
