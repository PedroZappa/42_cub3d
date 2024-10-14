/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500_raycaster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:14:31 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 10:44:33 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_get_delta(t_cub *cub);
static void	ft_get_small_delta(t_cub *cub);

/**
 * @brief Setup the direction of a ray
 * @param cub a point to a t_cub struct
 * @param x the x coordinate of thw image
 * @details 
 * - Normalize curr ray to range of -1 to 1
 * - Compute ray direction based on current ray
 * - DDA (Digital Differential Analyzer) algorithm calculations
**/
void	ft_get_ray(t_cub *cub, int x)
{
	double	curr_ray;

	curr_ray = (2 * x / (double)WINDOW_W - 1);
	cub->ray->ray_dir->x = cub->ray->vec_dir->x \
		+ cub->ray->camera->x * curr_ray;
	cub->ray->ray_dir->y = cub->ray->vec_dir->y \
		+ cub->ray->camera->y * curr_ray;
	ft_get_delta(cub);
	ft_get_small_delta(cub);
}

/**
 * @brief Computes the distance to next grid boundary
 * (avoiding division by 0)
 * @param cub a point to a t_cub struct
 **/
static void	ft_get_delta(t_cub *cub)
{
	if (cub->ray->ray_dir->x == 0)
		cub->ray->delta_dist->x = DBL_MAX;
	else
		cub->ray->delta_dist->x = fabs(1 / cub->ray->ray_dir->x);
	if (cub->ray->ray_dir->y == 0)
		cub->ray->delta_dist->y = DBL_MAX;
	else
		cub->ray->delta_dist->y = fabs(1 / cub->ray->ray_dir->y);
}

/**
 * @brief Computes the step & distance to next grid boundary
 * @param cub a point to a t_cub struct
 **/
static void	ft_get_small_delta(t_cub *cub)
{
	if (cub->ray->ray_dir->x >= 0)
	{
		cub->ray->small_delta->x = ((cub->ray->map->x + 1 - cub->ray->pos->x) \
			* cub->ray->delta_dist->x);
		cub->ray->step->x = 1;
	}
	else
	{
		cub->ray->small_delta->x = ((cub->ray->pos->x - cub->ray->map->x) \
			* cub->ray->delta_dist->x);
		cub->ray->step->x = -1;
	}
	if (cub->ray->ray_dir->y >= 0)
	{
		cub->ray->small_delta->y = ((cub->ray->map->y + 1 - cub->ray->pos->y) \
			* cub->ray->delta_dist->y);
		cub->ray->step->y = 1;
	}
	else
	{
		cub->ray->small_delta->y = ((cub->ray->pos->y - cub->ray->map->y) \
			* cub->ray->delta_dist->y);
		cub->ray->step->y = -1;
	}
}
