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
static void		ft_raycast(t_cub *cub, int x);

/**
 * @brief Render the image
 * @param cub a pointer to a t_cub struct
 * @return void
*/
void	ft_render(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return ;
	ft_render_image(cub);
	ft_render_fps(cub);
}

/**
 * @brief Draw the image & put it on the window
 * @param cub a pointer to a t_cub struct
*/
static int	ft_render_image(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return (FAILURE);
	ft_draw_image(cub);
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->wdw,
		cub->mlx->frame->img, 0, 0);
	return (SUCCESS);
}

/**
 * @brief Find the obstacle and draw the image accordingly
 * @param cub a pointer to a t_cub struct
*/
static void	ft_draw_image(t_cub *cub)
{
	int			height;
	int			x;

	x = 0;
	while (x < WINDOW_W)
	{
		ft_raycast(cub, x);
		height = WINDOW_H - 1;
		while (height > cub->ray->wall_top)
			ft_pixel_put(cub->mlx->frame, x, height--, \
				ft_rgb_to_int(cub->map->floor_color));
		height = cub->ray->wall_bottom;
		while (height >= 0)
			ft_pixel_put(cub->mlx->frame, x, height--, \
				ft_rgb_to_int(cub->map->ceiling_color));
		ft_ray_free(cub->ray);
		++x;
	}
}

/**
 * @brief Computes the ray using DDA
 * @param cub a pointer to a t_cub struct
 * @param x the x position of the ray
 * @return void
*/
static void	ft_raycast(t_cub *cub, int x)
{
	cub->ray = ft_ray_init(cub->pos->x, cub->pos->y);
	ft_get_ray(cub, x);
	ft_get_intersection(cub);
}
