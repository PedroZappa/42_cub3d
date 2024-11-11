/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   600_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:41:00 by passunca          #+#    #+#             */
/*   Updated: 2024/11/07 15:24:26 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Rotates the player
 * @param cub The cub structure
 * @details
 * The ROT_SPEED is dynamic, based on the distance to the object in front,
 * as the player moves closer to the object, the rotation speed increases.
 * Negative sign enures the rotation is counter-clockwise
 * Rotation Formula
 * x' = x * cos(θ) - y * sin(θ)
 * y' = x * sin(θ) + y * cos(θ)
 * Where θ is the rotation angle (here, rotate_speed).
**/
void	ft_turn(t_cub *cub, bool dir)
{
	double	prev_dir_x;
	double	prev_plane_x;
	double	angle;

	angle = (-1 * dir + (dir == 0)) * ROT_SPEED;
	prev_dir_x = cub->dir->x;
	prev_plane_x = cub->plane->x;
	cub->dir->x = prev_dir_x * cos(angle)
		- cub->dir->y * sin(angle);
	cub->dir->y = prev_dir_x * sin(angle)
		+ cub->dir->y * cos(angle);
	cub->plane->x = prev_plane_x * cos(angle)
		- cub->plane->y * sin(angle);
	cub->plane->y = prev_plane_x * sin(angle)
		+ cub->plane->y * cos(angle);
}
