/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:24:35 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 23:42:21 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_map	*ft_map_init(void)
{
	t_map	*ret;

	ret = malloc(sizeof(t_map));
	if (ret == NULL)
		return (NULL);
	ret->ceiling_color = -1;
	ret->floor_color = -1;
	ret->paths = ft_calloc(5, sizeof(char *));
	if (ret->paths == NULL)
		return (ft_vfree(ret), NULL);
	ret->imgs = ft_calloc(5, sizeof(void *));
	if (ret->imgs == NULL)
		return (ft_vfree(ret->paths), ft_vfree(ret), NULL);
	ret->map = NULL;
	ret->start_pos = NULL;
	ret->start_direction = INVALID;
	ret->height = 0;
	ret->width = 0;
	return (ret);
}

void	ft_map_destroy_imgs(t_map *map, t_mlx *mlx)
{
	int	i;

	if (map == NULL || mlx == NULL || mlx->ptr == NULL)
		return ;
	i = NORTH;
	while (i < EAST)
	{
		if (map->imgs[i])
		{
			mlx_destroy_image(mlx->ptr, map->imgs[i]);
			map->imgs[i] = NULL;
		}
		++i;
	}
}

void	ft_map_free(t_map *map)
{
	if (map == NULL)
		return ;
	ft_free_arr(map->map);
	ft_free_arr(map->paths);
	ft_vfree_arr(map->imgs);
	ft_vfree(map->start_pos);
	free(map);
}
