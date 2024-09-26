/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   105_map_verify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:28:26 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/26 19:28:26 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <fcntl.h>

int	ft_verify_borders(t_map *map);
int	ft_verify_paths(t_map *map);
int	ft_flood_fill(t_map *map, t_map *aux_map, int x, int y);

t_map	*ft_map_verify(t_map *map)
{
	if (map == NULL)
		return (NULL);
	if (map->ceiling_color == -1 || map->floor_color == -1)
		return (ft_parse_err(PARSE_COLORS), ft_map_free(map), NULL);
	if (map->start_direction == INVALID || map->start_pos == NULL)
		return (ft_parse_err(PARSE_DIR), ft_map_free(map), NULL);
	if (ft_verify_paths(map))
		return (ft_parse_err(PARSE_PATH), ft_map_free(map), NULL);
	if (ft_verify_borders(map))
		return (ft_parse_err(PARSE_BORD), ft_map_free(map), NULL);
	return (map);
}

int	ft_verify_paths(t_map *map)
{
	int	i;
	int	fd;

	if (map == NULL)
		return (FAILURE);
	i = NORTH;
	while (i < EAST)
	{
		if (map->paths[i] == NULL)
			return (FAILURE);
		fd = open(map->paths[i], O_RDONLY);
		if (fd < 0)
			return (FAILURE);
		close(fd);
		++i;
	}
	return (SUCCESS);
}

int	ft_verify_borders(t_map *map)
{
	t_map	aux_map;
	int		i;

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

int	ft_flood_fill(t_map *map, t_map *aux_map, int x, int y)
{
	char	*c;

	if (map == NULL || aux_map == NULL)
		return (FAILURE);
	c = ft_map_at_i_ref(aux_map, x, y);
	if (c == NULL)
		return (FAILURE);
	if (*c == 0)
		return (SUCCESS);
	// missing verify if '0' is not on border or near to space
	if (ft_flood_fill(map, aux_map, x - 1, y))
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x + 1, y))
		return (FAILURE);
	if (ft_flood_fill(map, aux_map, x, y - 1))
		return (FAILURE);
	return (ft_flood_fill(map, aux_map, x, y + 1));
}
