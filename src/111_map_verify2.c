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
	i = ft_flood_fill(map, &aux_map,
			map->start_pos->x, map->start_pos->y);
	return (ft_free_arr(aux_map.map), i);
}

static int	ft_flood_fill(t_map *map, t_map *aux_map, int x, int y)
{
	char	*c;

	if (map == NULL || aux_map == NULL)
		return (FAILURE);
	c = ft_map_at_i_ref(aux_map, x, y);
	if (c == NULL)
		return (FAILURE);
	if (*c == '1')
		return (SUCCESS);
	if (*c != '0')
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x - 1, y))
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x + 1, y))
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x, y - 1))
		return (FAILURE);
	return (ft_flood_fill(map, aux_map, x, y + 1));
}