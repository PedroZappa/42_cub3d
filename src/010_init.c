/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:38:51 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 12:11:49 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_alloc(void **component, size_t size);
static int	ft_alloc_ray(t_ray *ray);
static void	ft_init_ray_pos_dir(t_ray *ray, t_map *map);
void		ft_camera_init(t_cub *cub);

int	ft_raycast_init(t_cub *cub)
{
	cub->ray = ft_calloc(1, sizeof(t_ray));
	if (cub->ray == NULL)
		return (FAILURE);
	if (ft_alloc_ray(cub->ray) == FAILURE)
		return (FAILURE);
	ft_init_ray_pos_dir(cub->ray, cub->map);
	cub->ray->delta_dist->x = 0;
	cub->ray->delta_dist->y = 0;
	cub->ray->small_delta = 0;
	cub->ray->small_delta = 0;
	cub->ray->step->x = 0;
	cub->ray->step->y = 0;
	ft_camera_init(cub);
	return (SUCCESS);
}

static int	ft_alloc_ray(t_ray *ray)
{
	if (ft_alloc((void **)&ray->map, sizeof(t_point)) == FAILURE
		|| ft_alloc((void **)&ray->pos, sizeof(t_vec)) == FAILURE
		|| ft_alloc((void **)&ray->vec_dir, sizeof(t_vec)) == FAILURE
		|| ft_alloc((void **)&ray->ray_dir, sizeof(t_vec)) == FAILURE
		|| ft_alloc((void **)&ray->delta_dist, sizeof(t_vec)) == FAILURE
		|| ft_alloc((void **)&ray->small_delta, sizeof(t_vec)) == FAILURE
		|| ft_alloc((void **)&ray->step, sizeof(t_point)) == FAILURE
		|| ft_alloc((void **)&ray->camera, sizeof(t_vec)) == FAILURE
		|| ft_alloc((void **)&ray->camera_offset, sizeof(t_vec)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_alloc(void **component, size_t size)
{
	*component = ft_calloc(1, size);
	if (*component == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static void	ft_init_ray_pos_dir(t_ray *ray, t_map *map)
{
	ray->map->x = map->start_pos->x;
	ray->map->y = map->start_pos->y;
	ray->pos->x = ray->map->x;
	ray->pos->y = ray->map->y;
	ray->vec_dir->x = 0;
	ray->vec_dir->y = 0;
	if (map->start_direction == EAST)
		ray->vec_dir->x = 1;
	else if (map->start_direction == SOUTH)
		ray->vec_dir->y = 1;
	else if (map->start_direction == WEST)
		ray->vec_dir->x = -1;
	else if (map->start_direction == NORTH)
		ray->vec_dir->y = -1;
}

void	ft_camera_init(t_cub *cub)
{
	cub->ray->camera->x = -cub->ray->vec_dir->y;
	cub->ray->camera->y = cub->ray->vec_dir->x;
	ft_norm_vector(cub->ray->camera);
	cub->ray->camera->x *= FOV;
	cub->ray->camera->y *= FOV;
}
