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

/**
 * @brief Keyboard event hook function
 * @param keycode The key code of the pressed key
 * @param cub Pointer to the main game structure
 * @return SUCCESS always
 * @details 
 * This function handles keyboard events.
 * It exits the game if 'Escape' or 'q' is pressed.
*/
int	ft_hook_kb(int keycode, t_cub *cub)
{
	if (keycode == XK_Escape || keycode == 'q')
	{
		ft_cub_free(cub);
		exit(SUCCESS);
	}
	ft_hook_kb_move(keycode, cub);
	return (SUCCESS);
}

/**
 * @brief Main loop hook function
 * @param cub Pointer to the main game structure
 * @return SUCCESS always
 * @details
 * This function is called repeatedly in the main game loop. 
 * It clears the window and renders the game.
 */
int	ft_loop_hook(t_cub *cub)
{
	mlx_clear_window(cub->mlx->ptr, cub->mlx->wdw);
	ft_render(cub);
	return (SUCCESS);
}

/**
 * @brief Window close event hook function
 * @param cub Pointer to the main game structure
 * @return SUCCESS always
 * @details
 * This function is called when the window close event is triggered.
 * It frees resources and exits the game.
 */
int	ft_hook_quit(t_cub *cub)
{
	ft_cub_free(cub);
	exit(SUCCESS);
	return (SUCCESS);
}
