/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:38:51 by passunca          #+#    #+#             */
/*   Updated: 2024/10/11 20:26:32 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_camera_init(t_cub *cub);

int	ft_raycast_init(t_cub *cub)
{
	cub->ray = ft_calloc(1, sizeof(t_ray));
	if (cub->ray == NULL)
		return (FAILURE);
	cub->ray->map->x = cub->map->start_pos->x;
	cub->ray->map->y = cub->map->start_pos->y;
	cub->ray->pos->x = cub->ray->map->x;
	cub->ray->pos->y = cub->ray->map->y;
	cub->ray->vec_dir->x = 0;
	cub->ray->vec_dir->y = 0;
	if (cub->map->start_direction == EAST)
		cub->ray->vec_dir->x = 1;
	else if (cub->map->start_direction == SOUTH)
		cub->ray->vec_dir->y = 1;
	else if (cub->map->start_direction == WEST)
		cub->ray->vec_dir->x = -1;
	if (cub->map->start_direction == NORTH)
		cub->ray->vec_dir->y = -1;
	cub->ray->delta_dist->x = 0;
	cub->ray->delta_dist->y = 0;
	cub->ray->small_delta = 0;
	cub->ray->small_delta = 0;
	cub->ray->step->x = 0;
	cub->ray->step->y = 0;
	ft_camera_init(cub);
	return (SUCCESS);
}

void	ft_camera_init(t_cub *cub)
{
	cub->ray->camera->x = -cub->ray->vec_dir->y;
	cub->ray->camera->y = cub->ray->vec_dir->x;
	ft_norm_vector(cub->ray->camera);
	cub->ray->camera->x *= FOV;
	cub->ray->camera->y *= FOV;
}
