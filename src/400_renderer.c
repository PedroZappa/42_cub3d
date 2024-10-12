/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   400_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:29:38 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/12 09:20:11 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		ft_render_image(t_cub *cub);
static void		ft_draw_image(t_cub *cub);
static t_target	*ft_find_obstacle(t_cub *cub);
static t_target	ft_raycast(t_cub *cub, int x);

void	ft_render(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return ;
	ft_render_image(cub);
	ft_render_fps(cub);
}

static int	ft_render_image(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return (FAILURE);
	// TODO: Execute movement
	ft_draw_image(cub);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->wdw,
		cub->mlx->frame, 0, 0);
	return (SUCCESS);
}

static void	ft_draw_image(t_cub *cub)
{
	t_target	*target;
	int			height;
	int			x;

	target = ft_find_obstacle(cub);
	x = 0;
	while (x < WINDOW_W)
	{
		height = WINDOW_H;
		while (height > target[x].wall_top)
			ft_pixel_put(cub->mlx->frame, x, height--, \
				ft_rgb_to_int(cub->map->floor_color));
		// TODO : Draw Wall Texture
		height = target[x].wall_bottom;
		while (height > 0)
			ft_pixel_put(cub->mlx->frame, x, height--, \
				ft_rgb_to_int(cub->map->ceiling_color));
		++x;
	}
	free(target);
}

static t_target	*ft_find_obstacle(t_cub *cub)
{
	t_target	*target;
	int			x;

	target = ft_calloc(WINDOW_W, sizeof(t_target));
	if (target == NULL)
		return (ft_cub_free(cub), NULL);
	x = -1;
	while (++x < WINDOW_W)
		target[x] = ft_raycast(cub, x);
	cub->ray->center_raylen = target[WINDOW_W / 2].dist;
	return (target);
}

static t_target	ft_raycast(t_cub *cub, int x)
{
	t_target	ray_hitpoint;

	ft_compute_ray(cub, x);
	ft_get_intersection(cub, &ray_hitpoint);
	return (ray_hitpoint);
}
