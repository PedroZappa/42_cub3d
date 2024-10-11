/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   400_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:29:38 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 21:23:43 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_render_image(t_cub *cub);
static void	ft_render_fps(t_cub *cub);

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
	// TODO: Draw image
	mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->wdw, cub->mlx->img, 0, 0);
	return (SUCCESS);
}

static void	ft_render_fps(t_cub *cub)
{
	long			curr_time;
	static long		last_fps_update;
	static long		frame_count;
	static double	fps;
	char			*fps_str;

	curr_time = ft_timestamp();
	++frame_count;
	if ((curr_time - last_fps_update) >= 1000)
	{
		fps = (frame_count * 1000.0) / (curr_time - last_fps_update);
		frame_count = 0;
		last_fps_update = curr_time;
	}
	if (fps <= 0)
		fps = 1;
	fps_str = ft_itoa((int)fps);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw, 15, 25, HEX_WHITE, "FPS");
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw, 38, 25, HEX_GREEN, fps_str);
	ft_free(fps_str);
	cub->start_time = curr_time;
}
