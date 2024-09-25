/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:35:08 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 15:49:43 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cube_free(t_cube *cube)
{
	if (cube == NULL)
		return ;
	ft_vfree(cube->current_pos);
	cube->current_pos = NULL;
	ft_map_free(cube->map);
	cube->map = NULL;
	ft_mlx_free(cube->mlx);
	cube->mlx = NULL;
}

/**
 * 1. parse map
 * 2. start mlx
 * 3. game loop
*/
int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
		return (ft_err(ARG_ERR));
	cube = (t_cube){NULL, NULL, NULL};
	if (ft_parse_map(&cube, argv[1]))
		return (FAILURE);
	cube.mlx = ft_mlx_init(WINDOW_W, WINDOW_H, WINDOW_TITLE);
	if (cube.mlx == NULL)
		return (ft_cube_free(&cube), ft_err(MLX_ERR));
	if (ft_mlx_set_hooks(&cube))
		return (ft_cube_free(&cube), ft_err(MLX_ERR));
	mlx_loop(cube.mlx->ptr);
	ft_cube_free(&cube);
	return (SUCCESS);
}
