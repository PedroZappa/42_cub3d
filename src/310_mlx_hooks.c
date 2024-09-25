/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:53:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 15:59:30 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_hook_kb(int keycode, t_cube *cube)
{
	if (keycode == X11_ESC || keycode == 'q')
	{
		ft_cube_free(cube);
		exit(SUCCESS);
	}
	return (SUCCESS);
}

int	ft_hook_quit(t_cube *cube)
{
	ft_cube_free(cube);
	exit(SUCCESS);
	return (SUCCESS);
}
