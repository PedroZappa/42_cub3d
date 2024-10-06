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

int	ft_hook_loop(t_cub *cub)
{
	char	*timestamp;

	mlx_clear_window(cub->mlx->ptr, cub->mlx->wdw);
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 - 60, WINDOW_H / 2, HEX_GREEN, "Cub3D");
	timestamp = ft_itoa((int)ft_timestamp());
	mlx_string_put(cub->mlx->ptr, cub->mlx->wdw,
		WINDOW_W / 2 + 10, WINDOW_H / 2, HEX_WHITE, timestamp);
	ft_free(timestamp);
	return (SUCCESS);
}

int	ft_hook_quit(t_cub *cub)
{
	ft_cub_free(cub);
	exit(SUCCESS);
	return (SUCCESS);
}
