/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:38:51 by passunca          #+#    #+#             */
/*   Updated: 2024/10/11 19:18:10 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_camera_init(t_cub *cub);

int	ft_raycast_init(t_cub *cub)
{
	cub->raycast = ft_calloc(1, sizeof(t_raycast));
	if (cub->raycast == NULL)
		return (FAILURE);
	cub->raycast->map->x = cub->map->start_pos->x;
	cub->raycast->map->y = cub->map->start_pos->y;
	cub->raycast->pos->x = cub->raycast->map->x;
	cub->raycast->pos->y = cub->raycast->map->y;
	cub->raycast->vec_dir->x = 0; 
	cub->raycast->vec_dir->y = 0; 
	if (cub->map->start_direction == EAST)
		cub->raycast->vec_dir->x = 1;
	else if (cub->map->start_direction == SOUTH)
		cub->raycast->vec_dir->y = 1;
	else if (cub->map->start_direction == WEST)
		cub->raycast->vec_dir->x = -1;
	if (cub->map->start_direction == NORTH)
		cub->raycast->vec_dir->y = -1;
	cub->raycast->delta_dist->x = 0;
	cub->raycast->delta_dist->y = 0;
	ft_camera_init(cub);
	return (SUCCESS);
}

void	ft_camera_init(t_cub *cub)
{
	cub->raycast->camera->x = -cub->raycast->vec_dir->y;
	cub->raycast->camera->y = cub->raycast->vec_dir->x;
	ft_norm_vector(cub->raycast->camera);
	cub->raycast->camera->x *= FOV;
	cub->raycast->camera->y *= FOV;
}
