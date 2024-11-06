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

static int	ft_color_at(t_img *img, int tex_y, int tex_x)
{
	int	color;
	
	color = *(int *)(img->pix + tex_y * img->line_len
		+ tex_x * img->bpp / 8);
	return (color);
}

static int	ft_find_color(t_cub *cub, t_tex *tex, int tex_y)
{
	double	wall_x;
	int		tex_x;

	if (cub->ray->wall_dir % 2)
		wall_x = cub->pos->y + cub->ray->dist \
			* cub->ray->ray_dir->y;
	else
		wall_x = cub->pos->x + cub->ray->dist \
			* cub->ray->ray_dir->x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex->width;
	if (cub->ray->wall_dir % 2 && cub->ray->ray_dir->x > 0)
		tex_x = 64 - tex_x - 1;
	if (cub->ray->wall_dir % 2 == 0 && cub->ray->ray_dir->y < 0)
		tex_x = 64 - tex_x - 1;
	return (ft_color_at(tex->img, tex_y, tex_x));
}

static void	ft_draw_texture(t_cub *cub, int x)
{
	double	tex_pos;
	double	step;
	int		color;
	int		tex_y;
	double	height;
	t_tex	*tex;

	tex = cub->map->tex + cub->ray->wall_dir;
	step = 1.0 *  tex->height / cub->ray->wall_height;
	tex_pos = (cub->ray->wall_bottom - WINDOW_H / 2 + cub->ray->wall_height / 2) * step;
	height = cub->ray->wall_top;
	while (height > cub->ray->wall_bottom)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		color = ft_find_color(cub, tex, tex_y);
		ft_pixel_put(cub->mlx->frame, x, height, color);
		height--;
	}
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
		ft_draw_texture(cub, x);
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
