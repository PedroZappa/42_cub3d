/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   101_map_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:19:41 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/26 21:21:54 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Get the character at a specific point in the map
 * @param map Pointer to the map structure
 * @param point Pointer to the point structure containing x and y coordinates
 * @return SUCCESS(The character at the specified point)
 * @return FAILURE(-1 if the point is invalid)
 */
char	ft_map_at(t_map *map, t_point *point)
{
	if (point == NULL)
		return (-1);
	return (ft_map_at_i(map, point->x, point->y));
}

/**
 * @brief Get the character at a specific point in the map
 * @param map Pointer to the map structure
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 * @return SUCCESS(The character at the specified point)
 * @return FAILURE(-1 if the point is invalid)
 */
char	ft_map_at_i(t_map *map, int x, int y)
{
	if ((map == NULL) || (x >= (int)map->width)
		|| (y >= (int)map->height) || (x < 0) || (y < 0))
		return (-1);
	return (map->map[y][x]);
}

/**
 * @brief Get the character at a specific point in the map
 * @param map Pointer to the map structure
 * @param point Pointer to the point structure containing x and y coordinates
 * @return SUCCESS(The character at the specified point)
 * @return FAILURE(-1 if the point is invalid)
 */
char	*ft_map_at_ref(t_map *map, t_point *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_map_at_i_ref(map, point->x, point->y));
}

/**
 * @brief Get the character at a specific point in the map
 * @param map Pointer to the map structure
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 * @return SUCCESS(The character at the specified point)
 * @return FAILURE(-1 if the point is invalid)
 */
char	*ft_map_at_i_ref(t_map *map, int x, int y)
{
	if ((map == NULL) || (x >= (int)map->width)
		|| (y >= (int)map->height) || (x < 0 || y < 0))
		return (NULL);
	return (map->map[y] + x);
}
