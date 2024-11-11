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

int	ft_color_at(t_img *img, int x, int y)
{
	int	color;

	color = *(int *)(img->pix + y * img->line_len
			+ x * (img->bpp / 8));
	return (color);
}

int	ft_find_color(t_cub *cub, t_tex *tex, int y)
{
	double	wall;
	int		x;

	if (cub->ray->wall_dir > SOUTH)
		wall = cub->pos->y + cub->ray->dist \
			* cub->ray->ray_dir->y;
	else
		wall = cub->pos->x + cub->ray->dist \
			* cub->ray->ray_dir->x;
	wall -= floor(wall);
	x = wall * (double)tex->width;
	if (cub->ray->wall_dir > SOUTH && cub->ray->ray_dir->x > 0)
		x = tex->width - x - 1;
	if (cub->ray->wall_dir <= SOUTH && cub->ray->ray_dir->y < 0)
		x = tex->width - x - 1;
	return (ft_color_at(tex->img, x, y));
}
