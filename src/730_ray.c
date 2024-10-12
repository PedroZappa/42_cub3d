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

static t_vec	*ft_camera_init(t_vec *vec_dir);
static t_ray	*ft_ray_alloc_check(t_ray *ray);

t_ray	*ft_ray_init(t_point *start_pos, t_dir start_dir)
{
	t_ray	*ret;

	if (start_pos == NULL)
		return (NULL);
	ret = ft_calloc(1, sizeof(t_ray));
	if (ret == NULL)
		return (NULL);
	ret->map = ft_point_copy(start_pos);
	ret->pos = ft_vec_new(start_pos->x, start_pos->y);
	ret->vec_dir = ft_vec_dir(start_dir);
	ret->ray_dir = ft_vec_new(0, 0);
	ret->delta_dist = ft_vec_new(0, 0);
	ret->small_delta = ft_vec_new(0, 0);
	ret->step = ft_point_new(0, 0);
	ret->camera = ft_camera_init(ret->vec_dir);
	ret->camera_offset = ft_vec_new(0, 0);
	return (ft_ray_alloc_check(ret));
}

static t_ray	*ft_ray_alloc_check(t_ray *ray)
{
	if (ray == NULL || ray->map == NULL
		|| ray->pos == NULL || ray->vec_dir == NULL
		|| ray->vec_dir == NULL || ray->ray_dir == NULL
		|| ray->delta_dist == NULL || ray->small_delta == NULL
		|| ray->step == NULL || ray->camera == NULL
		|| ray->camera_offset == NULL)
		return (ft_ray_free(ray), NULL);
	return (ray);
}

static t_vec	*ft_camera_init(t_vec *vec_dir)
{
	t_vec	*ret;

	if (vec_dir == NULL)
		return (NULL);
	ret = ft_vec_new(-vec_dir->y, vec_dir->x);
	if (ret == NULL)
		return (NULL);
	ft_vec_norm(ret);
	ret->x *= FOV;
	ret->y *= FOV;
	return (ret);
}

void	ft_ray_free(t_ray *ray)
{
	if (ray == NULL)
		return ;
	ft_vfree(ray->map);
	ft_vfree(ray->pos);
	ft_vfree(ray->vec_dir);
	ft_vfree(ray->ray_dir);
	ft_vfree(ray->delta_dist);
	ft_vfree(ray->small_delta);
	ft_vfree(ray->step);
	ft_vfree(ray->camera);
	ft_vfree(ray->camera_offset);
	ft_bzero(ray, sizeof(t_ray));
	free(ray);
}
