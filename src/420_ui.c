/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   420_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:44:57 by passunca          #+#    #+#             */
/*   Updated: 2024/10/12 08:48:29 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_render_fps(t_cub *cub)
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
		cub->frame_time = (curr_time - last_fps_update) / 1000.0;
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
