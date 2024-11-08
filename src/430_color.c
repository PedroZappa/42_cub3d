/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   430_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:32:07 by passunca          #+#    #+#             */
/*   Updated: 2024/11/08 11:59:20 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_color_at(t_img *img, int tex_y, int tex_x)
{
	int	color;

	color = *(int *)(img->pix + tex_y * img->line_len
			+ tex_x * (img->bpp / 8));
	return (color);
}

int	ft_find_color(t_cub *cub, t_tex *tex, int tex_y)
{
	double	wall_x;
	int		tex_x;

	if (cub->ray->wall_dir <= SOUTH)
		wall_x = cub->pos->y + cub->ray->dist \
			* cub->ray->ray_dir->y;
	else
		wall_x = cub->pos->x + cub->ray->dist \
			* cub->ray->ray_dir->x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex->width;
	if (cub->ray->wall_dir <= SOUTH && cub->ray->ray_dir->x > 0)
		tex_x = tex->width - tex_x - 1;
	if (cub->ray->wall_dir > SOUTH && cub->ray->ray_dir->y < 0)
		tex_x = tex->width - tex_x - 1;
	return (ft_color_at(tex->img, tex_y, tex_x));
}
