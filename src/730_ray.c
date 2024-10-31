/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   730_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:24:00 by passunca          #+#    #+#             */
/*   Updated: 2024/10/13 20:24:06 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_ray	*ft_ray_alloc_check(t_ray *ray);

/**
 * @brief Initialize a new ray structure
 * @param start_pos The starting position of the ray
 * @param start_dir The starting direction of the ray
 * @return SUCCESS(Pointer to the newly created t_ray structure)
 * @return FAILURE(NULL if allocation fails or start_pos is NULL)
 * @details
 * This function allocates and initializes a new t_ray structure with the given
 * starting position and direction. It sets up all necessary components for
 * raycasting, including map position, direction vectors, and camera parameters.
 */
t_ray	*ft_ray_init(t_point *start_pos, t_vec *orient)
{
	t_ray	*ret;

	if (start_pos == NULL)
		return (NULL);
	ret = ft_calloc(1, sizeof(t_ray));
	if (ret == NULL)
		return (NULL);
	ret->map = start_pos;
	ret->pos = ft_vec_new(start_pos->x, start_pos->y);
	ret->vec_dir = orient;
	ret->ray_dir = ft_vec_new(0, 0);
	ret->delta_dist = ft_vec_new(0, 0);
	ret->small_delta = ft_vec_new(0, 0);
	ret->step = ft_point_new(0, 0);
	return (ft_ray_alloc_check(ret));
}

/**
 * @brief Check if all allocations in a t_ray structure were successful
 * @param ray Pointer to the t_ray structure to check
 * @return SUCCESS(The input ray pointer if all allocations were successful)
 * @return FAILURE(NULL if any allocation failed, after freeing the ray)
 * @details
 * This function verifies that all pointer members of the t_ray structure
 * were successfully allocated. If any allocation failed, it frees the entire
 * structure and returns NULL.
 */
static t_ray	*ft_ray_alloc_check(t_ray *ray)
{
	if (ray == NULL || ray->map == NULL
		|| ray->pos == NULL || ray->vec_dir == NULL
		|| ray->vec_dir == NULL || ray->ray_dir == NULL
		|| ray->delta_dist == NULL || ray->small_delta == NULL
		|| ray->step == NULL)
		return (ft_ray_free(ray), NULL);
	return (ray);
}

/**
 * @brief Free all memory associated with a t_ray structure
 * @param ray Pointer to the t_ray structure to be freed
 * @return None
 * @details
 * This function frees all dynamically allocated members of the t_ray
 * structure, zeros out the memory, and then frees the structure itself.
 * It safely handles NULL input.
 */
void	ft_ray_free(t_ray *ray)
{
	if (ray == NULL)
		return ;
	ft_vfree(ray->pos);
	ft_vfree(ray->vec_dir);
	ft_vfree(ray->ray_dir);
	ft_vfree(ray->delta_dist);
	ft_vfree(ray->small_delta);
	ft_vfree(ray->step);
	ft_bzero(ray, sizeof(t_ray));
	free(ray);
}
