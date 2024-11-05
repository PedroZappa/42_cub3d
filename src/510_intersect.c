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

static void	ft_check_wall_dir(int step, t_ray *target, t_coord side);
static void	ft_get_wall_height(t_ray *ray);
// static void	ft_get_tile_offset(t_ray ray, t_target *target, t_tex tex);

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
			ft_check_wall_dir(cub->ray->step->x, cub->ray, X);
		}
		else
		{
			cub->ray->small_delta->y += cub->ray->delta_dist->y;
			cub->ray->map->y += cub->ray->step->y;
			ft_check_wall_dir(cub->ray->step->y, cub->ray, Y);
		}
		/*printf(
			"Char: '%d' '%c' Point: (%i, %i)\n"
			"Small delta: (%f, %f)\n"
			"Delta dist: (%f, %f)\n"
			"Step: (%d, %d)\n\n",
			c,
			c,
			cub->ray->map->x,
			cub->ray->map->y,
			cub->ray->small_delta->x,
			cub->ray->small_delta->y,
			cub->ray->delta_dist->x,
			cub->ray->delta_dist->y,
			cub->ray->step->x,
			cub->ray->step->y
			);*/
		if (ft_map_at(cub->map, cub->ray->map) == '1')
			break ;
	}
	ft_get_wall_height(cub->ray);
	// ft_get_tile_offset(*cub->ray, target, cub->map->tex[target->wall_dir]);
}

/**
 * @brief Set whioh side of a wall the ray has hit
 * @param step From 1 or -1
 * @param target Current camera target
 * @param side X or Y
**/
static void	ft_check_wall_dir(int step, t_ray *target, t_coord side)
{
	if (side == X)
	{
		if (step == 1)
			target->wall_dir = WEST;
		else if (step == -1)
			target->wall_dir = EAST;
	}
	else if (side == Y)
	{
		if (step == 1)
			target->wall_dir = NORTH;
		else if (step == -1)
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
	if ((ray->wall_dir == NORTH) || (ray->wall_dir == SOUTH))
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

/**
 * @brief Compute the horizxontal offset for texture mapping
 * @param ray A pointer to a t_ray struct
 * @param target Current camera target
 * @param tex The texture to be mapped
 * @details
 * - Get ray hitpoint on the wall
 * - Compute the offset within the wall tile for texture mapping
 * - Adjust the texture's x coordinate for correct texture orientation
**/
// static void	ft_get_tile_offset(t_ray ray, t_target *target, t_tex tex)
// {
// 	if ((target->wall_dir == NORTH) || (target->wall_dir == SOUTH))
// 		target->hitpoint = ray.pos->y + target->dist * ray.ray_dir->y;
// 	else
// 		target->hitpoint = ray.pos->x + target->dist * ray.ray_dir->x;
// 	target->tile_offset = target->hitpoint - floor(target->hitpoint);
// 	target->tex_x = (target->tile_offset * (double)tex.width);
// 	if (((target->wall_dir == NORTH) || ((target->wall_dir == SOUTH) 
// 			&& (ray.ray_dir->y < 0))) || ((target->wall_dir == WEST)
// 		|| ((target->wall_dir == EAST) && (target->wall_dir > 0))))
// 		target->tex_x = (tex.width - target->tex_x - 1);
// }
