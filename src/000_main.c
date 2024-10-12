/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:35:08 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 19:26:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cub_free(t_cub *cub);

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		return (ft_err(ARG_ERR));
	cub = (t_cub){NULL, NULL, NULL, NULL, NULL, 0};
	if (ft_parse_map(&cub, argv[1]))
		return (FAILURE);
	cub.ray = ft_ray_init(cub.map->start_pos,
			cub.map->start_direction);
	if (cub.ray == NULL)
		return (ft_cub_free(&cub), ft_err(RAYCAST_ERR));
	cub.mlx = ft_mlx_init();
	if (cub.mlx == NULL)
		return (ft_cub_free(&cub), ft_err(MLX_ERR));
	if (ft_load_images(cub.mlx, cub.map))
		return (ft_cub_free(&cub), ft_err(LOAD_ERR));
	if (ft_mlx_new_window(&cub, WINDOW_W,
			WINDOW_H, WINDOW_TITLE))
		return (ft_cub_free(&cub), ft_err(MLX_ERR));
	mlx_loop(cub.mlx->ptr);
	ft_cub_free(&cub);
	return (SUCCESS);
}

void	ft_cub_free(t_cub *cub)
{
	if (cub == NULL)
		return ;
	ft_vfree(cub->current_pos);
	ft_vfree(cub->orientation);
	ft_ray_free(cub->ray);
	ft_map_destroy_imgs(cub->map, cub->mlx);
	ft_map_free(cub->map);
	ft_mlx_free(cub->mlx);
	ft_bzero(cub, sizeof(cub));
}
