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
void ft_turn(t_cub *cub, bool dir)
{
	double prev_dir_x;
	double prev_plane_x;
	double rot_speed;

	rot_speed = ((-1 * dir) * ROT_SPEED * (1 + (1 / pow(cub->ray->dist, 2))));
	prev_dir_x = cub->dir->x;
	prev_plane_x = cub->plane->x;
	cub->dir->x = prev_dir_x * cos(rot_speed) - cub->dir->y * sin(rot_speed);
	cub->dir->y = prev_dir_x * sin(rot_speed) + cub->dir->y * cos(rot_speed);
	cub->plane->x = prev_plane_x * cos(rot_speed) + cub->plane->y * sin(rot_speed);
	cub->plane->y = prev_plane_x * sin(rot_speed) + cub->plane->y * cos(rot_speed);
}
