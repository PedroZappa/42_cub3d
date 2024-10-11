/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:53:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 20:33:51 by passunca         ###   ########.fr       */
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

int	ft_loop_hook(t_cub *cub)
{
	mlx_clear_window(cub->mlx->ptr, cub->mlx->wdw);
	ft_render(cub);
	return (SUCCESS);
}

int	ft_hook_quit(t_cub *cub)
{
	ft_cub_free(cub);
	exit(SUCCESS);
	return (SUCCESS);
}
