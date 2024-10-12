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

static int	ft_verify_paths(t_map *map);
static int	ft_verify_size(t_map *map);
static int	ft_verify_color(t_rgb rgb);
static int	ft_verify_content(t_map *map);

/**
 * @brief Verify if the map is valid
 * @param map a pointer to a t_map struct
 * @return a pointer to a valid t_map struct
 * @return NULL if the map is not valid
*/
t_map	*ft_map_verify(t_map *map)
{
	if (map == NULL)
		return (NULL);
	if (ft_verify_color(map->ceiling_color)
		|| ft_verify_color(map->floor_color))
		return (ft_parse_err(PARSE_COLORS), ft_map_free(map), NULL);
	if (map->start_direction == INVALID || map->start_pos == NULL)
		return (ft_parse_err(PARSE_DIR), ft_map_free(map), NULL);
	if (ft_verify_size(map))
		return (ft_map_free(map), NULL);
	if (ft_verify_content(map))
		return (ft_parse_err(PARSE_CONT), ft_map_free(map), NULL);
	if (ft_verify_paths(map))
		return (ft_parse_err(PARSE_PATH), ft_map_free(map), NULL);
	if (ft_verify_borders(map))
		return (ft_parse_err(PARSE_BORD), ft_map_free(map), NULL);
	return (map);
}

/**
 * @brief Verify if the color is valid
 * @param rgb a pointer to a t_rgb struct
 * @return SUCCESS(if the colors are valid)
 * @return FAILURE(if the colors are not valid)
*/
static int	ft_verify_color(t_rgb rgb)
{
	return (rgb.b < 0 || rgb.b > 255
		|| rgb.g < 0 || rgb.g > 255
		|| rgb.r < 0 || rgb.r > 255);
}

/**
 * @brief Verify if the image paths are valid
 * @param map a pointer to a t_map struct
 * @return SUCCESS(if the map is valid)
 * @return FAILURE(if the map is not valid)
*/
static int	ft_verify_paths(t_map *map)
{
	int	i;
	int	fd;

	if (map == NULL)
		return (FAILURE);
	i = NORTH;
	while (i <= EAST)
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

/**
 * @brief Verify the size consistency of the map
 * @param map Pointer to the map structure
 * @return SUCCESS if the map size is consistent, FAILURE otherwise
 */
static int	ft_verify_size(t_map *map)
{
	size_t	i;
	size_t	len;

	if (map == NULL)
		return (FAILURE);
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == NULL)
			return (FAILURE);
		len = ft_strlen(map->map[i]);
		if (len != map->width)
			return (ft_parse_size_err(TRUE, map->width, len));
		i++;
	}
	if (i != map->height)
		return (ft_parse_size_err(FALSE, map->height, i));
	return (SUCCESS);
}

/**
 * @brief Verify the content of the map
 * @param map Pointer to the map structure
 * @return SUCCESS if the map content is valid, FAILURE otherwise
 */
static int	ft_verify_content(t_map *map)
{
	size_t	i;
	size_t	j;
	char	c;

	if (map == NULL)
		return (FAILURE);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->width)
		{
			c = ft_map_at_i(map, j, i);
			if (!ft_isspace(c) && c != '1'
				&& c != '0')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
