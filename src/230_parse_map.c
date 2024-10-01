/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   230_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:45:32 by passunca          #+#    #+#             */
/*   Updated: 2024/10/01 11:47:23 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_parse_player(char *line, t_map *map);

int	ft_parsing_map(char *line, t_map *map)
{
	static int	line_count = 0;
	size_t		line_width;

	if (map == NULL || line == NULL)
		return (ft_err(FILE_ERR));
	if (ft_isalpha(line[0]))
		return (FAILURE);
	map->map[line_count] = ft_strdup(line);
	if (map->map[line_count] == NULL)
		return (ft_err(MEM_ERR));
	line_width = ft_strlen(line);
	if (map->width < line_width)
		map->width = line_width;
	ft_parse_player(line, map);
	++line_count;
	return (SUCCESS);
}

static void	ft_parse_player(char *line, t_map *map)
{
	static int	curr_line;
	size_t		col;
	t_dir		dir;

	col = 0;
	curr_line = 0;
	dir = INVALID;
	while (col < map->width)
	{
		while (++dir <= EAST)
		{
			if (ft_strncmp(&line[col], g_dirs[dir], 1) == 0)
			{
				map->start_direction = g_dirs[dir][0];
				map->start_pos->x = (int)col;
				map->start_pos->y = curr_line;
				return ;
			}
		}
		dir = INVALID;
		++col;
	}
	++curr_line;
}
