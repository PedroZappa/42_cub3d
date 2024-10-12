/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   111_map_verify2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:46:33 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/27 21:00:12 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_flood_fill(t_map *map, t_map *aux_map, int x, int y);

/**
 * @brief Verify the borders of the map using the flood fill algorithm
 * @param map Pointer to the map structure
 * @return SUCCESS if the map borders are valid, FAILURE if invalid or an error occurs
 */
int	ft_verify_borders(t_map *map)
{
	t_map	aux_map;
	size_t	i;

	if (map == NULL)
		return (FAILURE);
	aux_map.map = ft_calloc(map->height + 1, sizeof(char *));
	if (aux_map.map == NULL)
		return (FAILURE);
	i = 0;
	while (i < map->height)
	{
		aux_map.map[i] = ft_calloc(map->width + 1, sizeof(char));
		if (aux_map.map[i] == NULL)
			return (ft_free_arr(aux_map.map), FAILURE);
		++i;
	}
	aux_map.width = map->width;
	aux_map.height = map->height;
	i = ft_flood_fill(map, &aux_map,
			map->start_pos->x, map->start_pos->y);
	return (ft_free_arr(aux_map.map), i);
}

/**
 * @brief Perform a flood fill algorithm on the map
 * @param map Pointer to the original map structure
 * @param aux_map Pointer to an auxiliary map structure used for flood fill
 * @param x Starting x-coordinate for flood fill
 * @param y Starting y-coordinate for flood fill
 * @return SUCCESS if flood fill completes successfully, FAILURE if an error occurs
 */
static int	ft_flood_fill(t_map *map, t_map *aux_map, int x, int y)
{
	char	*c1;
	char	*c2;

	if (map == NULL || aux_map == NULL)
		return (FAILURE);
	c1 = ft_map_at_i_ref(map, x, y);
	c2 = ft_map_at_i_ref(aux_map, x, y);
	if (c1 == NULL || c2 == NULL)
		return (FAILURE);
	if (*c2 == 1)
		return (SUCCESS);
	*c2 = 1;
	if (*c1 == '1')
		return (SUCCESS);
	if (*c1 != '0')
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x - 1, y))
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x + 1, y))
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x, y - 1))
		return (FAILURE);
	return (ft_flood_fill(map, aux_map, x, y + 1));
}
