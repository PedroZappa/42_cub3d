/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500_raycaster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:14:31 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 09:47:06 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_get_small_delta_dist(t_cub *cub);
static void	ft_get_big_delta_dist(t_cub *cub);

void	ft_compute_ray(t_cub *cub, int x)
{
	double	curr_ray;

	curr_ray = (2 * x / (double)WINDOW_W - 1);
	cub->raycast->ray_dir->x = cub->raycast->vec_dir->x \
		+ cub->raycast->camera->x * curr_ray;
	cub->raycast->ray_dir->y = cub->raycast->vec_dir->y \
		+ cub->raycast->camera->y * curr_ray;
	ft_get_small_delta_dist(cub);
	ft_get_big_delta_dist(cub);
}

static void	ft_get_small_delta_dist(t_cub *cub)
{
	(void)cub;
}

static void	ft_get_big_delta_dist(t_cub *cub)
{
	(void)cub;
}

void	ft_get_intersection(t_cub *cub, t_target *target)
{
	(void)cub;
	(void)target;
}
