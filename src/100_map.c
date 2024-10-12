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

/**
 * @brief Initialize the t_map struct
 * @malloc Memory for the t_map struct
 * @return a pointer to a initialized t_map struct
*/
t_map	*ft_map_init(void)
{
	t_map	*ret;

	ret = malloc(sizeof(t_map));
	if (ret == NULL)
		return (NULL);
	ret->ceiling_color = (t_rgb){-1, -1, -1};
	ret->floor_color = (t_rgb){-1, -1, -1};
	ret->paths = ft_calloc(5, sizeof(char *));
	if (ret->paths == NULL)
		return (ft_vfree(ret), NULL);
	ft_bzero(ret->paths, 5);
	ft_bzero(ret->tex, 4 * sizeof(t_tex));
	ret->map = NULL;
	ret->start_pos = NULL;
	ret->start_direction = INVALID;
	ret->height = 0;
	ret->width = 0;
	return (ret);
}

/**
 * @brief Deallocate all rendered images
 * @param map a pointer to a t_map struct
 * @param mlx a pointer to a t_mlx struct
 * @return void
*/
void	ft_map_destroy_imgs(t_map *map, t_mlx *mlx)
{
	int	i;

	if (map == NULL || mlx == NULL || mlx->ptr == NULL)
		return ;
	i = NORTH;
	while (i <= EAST)
	{
		if (map->tex[i].img)
			ft_image_destroy(map->tex[i].img, mlx->ptr);
		map->tex[i].img = NULL;
		++i;
	}
}

/**
 * @brief Deallocate and erase t_map struct
 * @param map a pointer to a t_map struct
*/
void	ft_map_free(t_map *map)
{
	if (map == NULL)
		return ;
	ft_free_arr(map->map);
	ft_free_arr(map->paths);
	ft_vfree(map->start_pos);
	ft_bzero(map, sizeof(t_map));
	free(map);
}
