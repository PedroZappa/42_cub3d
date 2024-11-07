/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   320_mlx_hooks_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:52:17 by gfragoso          #+#    #+#             */
/*   Updated: 2024/11/07 14:45:34 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_kb_move_up(t_cub *cub)
{
	t_vec	vec;

	vec = (t_vec){cub->pos->x + cub->dir->x * MOV_SPEED,
		cub->pos->y + cub->dir->y * MOV_SPEED};
	printf("new vec (%f, %f)\n", vec.x, vec.y);
	if (ft_map_at_i(cub->map, vec.x, cub->pos->y) == '0')
		cub->pos->x = vec.x;
	if (ft_map_at_i(cub->map, cub->pos->x, vec.y) == '0')
		cub->pos->y = vec.y;
	if (ft_map_at_i(cub->map, vec.x, vec.y) == '0')
	{
		cub->pos->x = vec.x;
		cub->pos->y = vec.y;
	}
}

static void	ft_kb_move_down(t_cub *cub)
{
	t_vec	vec;

	vec = (t_vec){cub->pos->x - cub->dir->x * MOV_SPEED,
		cub->pos->y - cub->dir->y * MOV_SPEED};
	printf("new vec (%f, %f)\n", vec.x, vec.y);
	if (ft_map_at_i(cub->map, vec.x, cub->pos->y) == '0')
		cub->pos->x = vec.x;
	if (ft_map_at_i(cub->map, cub->pos->x, vec.y) == '0')
		cub->pos->y = vec.y;
	if (ft_map_at_i(cub->map, vec.x, vec.y) == '0')
	{
		cub->pos->x = vec.x;
		cub->pos->y = vec.y;
	}
}

static void	ft_kb_move_left(t_cub *cub)
{
	t_vec	vec;

	vec = (t_vec){cub->pos->x - cub->dir->y * MOV_SPEED,
		cub->pos->y + cub->dir->x * MOV_SPEED};
	if (ft_map_at_i(cub->map, vec.x, cub->pos->y) == '0')
		cub->pos->x = vec.x;
	if (ft_map_at_i(cub->map, cub->pos->x, vec.y) == '0')
		cub->pos->y = vec.y;
	if (ft_map_at_i(cub->map, vec.x, vec.y) == '0')
	{
		cub->pos->x = vec.x;
		cub->pos->y = vec.y;
	}
}

static void	ft_kb_move_right(t_cub *cub)
{
	t_vec	vec;

	vec = (t_vec){cub->pos->x + cub->dir->y * MOV_SPEED,
		cub->pos->y - cub->dir->x * MOV_SPEED};
	if (ft_map_at_i(cub->map, vec.x, cub->pos->y) == '0')
		cub->pos->x = vec.x;
	if (ft_map_at_i(cub->map, cub->pos->x, vec.y) == '0')
		cub->pos->y = vec.y;
	if (ft_map_at_i(cub->map, vec.x, vec.y) == '0')
	{
		cub->pos->x = vec.x;
		cub->pos->y = vec.y;
	}
}

void	ft_hook_kb_move(int keycode, t_cub *cub)
{
	if (cub == NULL)
		return ;
	if (keycode == 'w')
		ft_kb_move_up(cub);
	if (keycode == 's')
		ft_kb_move_down(cub);
	if (keycode == 'a')
		ft_kb_move_left(cub);
	if (keycode == 'd')
		ft_kb_move_right(cub);
	if (keycode == XK_Left)
		ft_turn_left(cub);
	if (keycode == XK_Right)
		ft_turn_right(cub);
	
}
