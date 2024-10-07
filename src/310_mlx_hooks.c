/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:53:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 16:23:43 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_hook_kb(int keycode, t_cub *cub)
{
	if (keycode == X11_ESC || keycode == 'q')
	{
		ft_cub_free(cub);
		exit(SUCCESS);
	}
	return (SUCCESS);
}

void	ft_show_loaded_details(t_cub *cub)
{
	char	*c;

	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 - 90, 120,
		HEX_WHITE, "Ceiling Color");
	c = ft_itoa(cub->map->ceiling_color.r);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 10, 120, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->map->ceiling_color.g);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 40, 120, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->map->ceiling_color.b);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 70, 120, HEX_WHITE, c);
	ft_free(c);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 - 90, 120 + 20,
		HEX_WHITE, "Floor Color");
	c = ft_itoa(cub->map->floor_color.r);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 10, 120 + 20, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->map->floor_color.g);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 40, 120 + 20, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->map->floor_color.b);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 70, 120 + 20, HEX_WHITE, c);
	ft_free(c);
	for (t_dir i = NORTH; i <= EAST; i++)
	{
		mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
			WINDOW_W / 2 - 90, 140 + 40 + (i * 20),
			HEX_WHITE, cub->map->paths[i]);
	}
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 - 90, 240 + 40,
		HEX_WHITE, "Start Pos");
	c = ft_itoa(cub->current_pos->x);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 10, 240 + 40, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->current_pos->y);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 40, 240 + 40, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->current_pos->z);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 70, 240 + 40, HEX_WHITE, c);
	ft_free(c);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 - 90, 260 + 40,
		HEX_WHITE, "Start Dir");
	c = ft_itoa(cub->orientation->x);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 10, 260 + 40, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->orientation->y);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 40, 260 + 40, HEX_WHITE, c);
	ft_free(c);
	c = ft_itoa(cub->orientation->z);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 70, 260 + 40, HEX_WHITE, c);
	ft_free(c);
	for (size_t i = 0; i < cub->map->height; i++)
	{
		mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
			WINDOW_W / 2 - 90, 220 + 40 + ((i + 4) * 20),
			HEX_WHITE, cub->map->map[i]);
	}
}

int	ft_hook_loop(t_cub *cub)
{
	char	*timestamp;

	mlx_clear_window(cub->mlx->ptr, cub->mlx->wdw);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 - 60, 100, HEX_GREEN, "Cub3D");
	timestamp = ft_itoa((int)ft_timestamp());
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 10, 100, HEX_WHITE, timestamp);
	ft_show_loaded_details(cub);
	ft_free(timestamp);
	return (SUCCESS);
}

int	ft_hook_quit(t_cub *cub)
{
	ft_cub_free(cub);
	exit(SUCCESS);
	return (SUCCESS);
}
