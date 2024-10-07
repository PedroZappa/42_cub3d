/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   230_parse_headers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:25:55 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:25:55 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_try_parse_texture(char **line, t_map *map, t_dir dir);

int	ft_parse_headers(char *line, t_map *map)
{
	const char	*g_dirs[] = {"NO", "SO", "WE", "EA"};
	t_dir		dir;

	if (map == NULL || line == NULL)
		return (FAILURE);
	dir = INVALID;
	if (ft_strcmp(line, "\n") == 0)
		return (SUCCESS);
	while (++dir <= EAST)
	{
		if (ft_strncmp(line, g_dirs[dir], 2) == 0)
			return (ft_try_parse_texture(&line, map, dir));
	}
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		return (ft_parsing_rgb(line, map));
	if (*line != '\0')
		return (ft_parse_err(PARSE_INV_LINE), FAILURE);
	return (SUCCESS);
}

static int	ft_try_parse_texture(char **line, t_map *map, t_dir dir)
{
	const char	*g_dirs[] = {"NO", "SO", "WE", "EA"};
	char		*nl;

	if (line == NULL || *line == NULL
		|| map == NULL || dir == INVALID)
		return (FAILURE);
	*line += 2;
	while (ft_isspace(**line))
		++(*line);
	nl = ft_strchr(*line, '\n');
	if (nl != NULL)
		*nl = '\0';
	if (map->paths[dir] != NULL)
		return (ft_texture_dupl_err(g_dirs[dir]), FAILURE);
	map->paths[dir] = ft_strdup(*line);
	return (SUCCESS);
}
