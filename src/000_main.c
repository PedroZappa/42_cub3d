/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:35:08 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 16:23:43 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cub_free(t_cub *cub);

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		return (ft_err(ARG_ERR));
	cub = (t_cub){NULL, NULL, NULL, NULL, 0};
	if (ft_parse_map(&cub, argv[1]))
		return (FAILURE);
	cub.mlx = ft_mlx_init(WINDOW_W, WINDOW_H, WINDOW_TITLE);
	if (cub.mlx == NULL)
		return (ft_cub_free(&cub), ft_err(MLX_ERR));
	if (ft_mlx_set_hooks(&cub))
		return (ft_cub_free(&cub), ft_err(MLX_ERR));
	ft_render(&cub);
	mlx_loop(cub.mlx->ptr);
	ft_cub_free(&cub);
	return (SUCCESS);
}

void	ft_render(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return ;
	// ft_draw_map(cub);
	// ft_place_player(cub);
	// mlx_put_image_to_window(cub->mlx->ptr, cub->mlx->wdw,
	// 	cub->mlx->img, 0, 0);
}

void	ft_cub_free(t_cub *cub)
{
	if (cub == NULL)
		return ;
	ft_vfree(cub->current_pos);
	cub->current_pos = NULL;
	ft_vfree(cub->orientation);
	cub->orientation = NULL;
	ft_map_free(cub->map);
	cub->map = NULL;
	ft_mlx_free(cub->mlx);
	cub->mlx = NULL;
}
