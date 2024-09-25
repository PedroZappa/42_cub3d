/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:24:35 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 16:03:14 by gfragoso         ###   ########.fr       */
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
	ret->paths = NULL;
	ret->imgs = NULL;
	ret->map = NULL;
	ret->start_pos = NULL;
	ret->start_direction = INVALID;
	return (ret);
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
