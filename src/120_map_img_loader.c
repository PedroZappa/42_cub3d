/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   120_map_img_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:32:53 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/12 14:50:56 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_load_images(t_mlx *mlx, t_map *map)
{
	int		i;

	if (map == NULL)
		return (FAILURE);
	i = NORTH;
	while (i <= EAST)
	{
		if (map->paths[i] == NULL)
			return (FAILURE);
		map->tex[i].img = mlx_xpm_file_to_image(mlx->ptr, map->paths[i],
				&map->tex[i].width, &map->tex[i].height);
		if (map->tex[i].img == NULL)
			return (FAILURE);
		++i;
	}
	
	return (SUCCESS);
}
