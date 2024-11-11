/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   320_mlx_hooks_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:52:17 by gfragoso          #+#    #+#             */
/*   Updated: 2024/11/07 15:27:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_kb_move_up(t_cub *cub)
{
	cub->pos->x = cub->pos->x + cub->dir->x * MOV_SPEED;
	cub->pos->y = cub->pos->y + cub->dir->y * MOV_SPEED;
}

static void	ft_kb_move_down(t_cub *cub)
{
	cub->pos->x = cub->pos->x - cub->dir->x * MOV_SPEED;
	cub->pos->y = cub->pos->y - cub->dir->y * MOV_SPEED;
}

static void	ft_kb_move_left(t_cub *cub)
{
	cub->pos->x = cub->pos->x + cub->dir->y * MOV_SPEED;
	cub->pos->y = cub->pos->y - cub->dir->x * MOV_SPEED;
}

static void	ft_kb_move_right(t_cub *cub)
{
	cub->pos->x = cub->pos->x - cub->dir->y * MOV_SPEED;
	cub->pos->y = cub->pos->y + cub->dir->x * MOV_SPEED;
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
		ft_turn(cub, true);
	if (keycode == XK_Right)
		ft_turn(cub, false);
}
