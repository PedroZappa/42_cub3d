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

static int	ft_verify_paths(t_map *map);
static int	ft_verify_size(t_map *map);
static int	ft_verify_color(t_rgb rgb);

t_map	*ft_map_verify(t_map *map)
{
	if (map == NULL)
		return (NULL);
	if (SKIP_VERIFY)
		return (map);
	if (ft_verify_color(map->ceiling_color)
		|| ft_verify_color(map->floor_color))
		return (ft_parse_err(PARSE_COLORS), ft_map_free(map), NULL);
	if (map->start_direction == INVALID || map->start_pos == NULL)
		return (ft_parse_err(PARSE_DIR), ft_map_free(map), NULL);
	if (ft_verify_size(map))
		return (ft_parse_err(PARSE_SIZE), ft_map_free(map), NULL);
	if (ft_verify_paths(map))
		return (ft_parse_err(PARSE_PATH), ft_map_free(map), NULL);
	if (ft_verify_borders(map))
		return (ft_parse_err(PARSE_BORD), ft_map_free(map), NULL);
	return (map);
}

static int	ft_verify_color(t_rgb rgb)
{
	return (rgb.b < 0 || rgb.b > 255
		|| rgb.g < 0 || rgb.g > 255
		|| rgb.r < 0 || rgb.r > 255);
}

static int	ft_verify_paths(t_map *map)
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

static int	ft_verify_size(t_map *map)
{
	size_t	i;

	if (map == NULL)
		return (FAILURE);
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == NULL)
			return (FAILURE);
		if (ft_strlen(map->map[i]) != map->width)
			return (FAILURE);
		i++;
	}
	return (i != map->height);
}
