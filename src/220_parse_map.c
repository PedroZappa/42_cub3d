/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   220_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:26:03 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:26:03 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_norm_line(t_map *map, char *line, int line_n);
static void	ft_parse_player(t_map *map, int line_n);

/**
 * @brief Parse a line of the map
 * @param line The input line to parse
 * @param map Pointer to the map structure
 * @return SUCCESS if parsing is successful, FAILURE otherwise
 */
int	ft_parsing_map(char *line, t_map *map)
{
	static int	line_n = 0;

	if (map == NULL || line == NULL)
		return (ft_err(PARSE_ERR));
	if (ft_isalpha(line[0]))
		return (FAILURE);
	ft_norm_line(map, line, line_n);
	ft_parse_player(map, line_n);
	++line_n;
	return (SUCCESS);
}

/**
 * @brief Normalize a line of the map by padding it to the correct width
 * @param map Pointer to the map structure
 * @param line The input line to normalize
 * @param line_n The line number in the map
 */
static void	ft_norm_line(t_map *map, char *line, int line_n)
{
	char		*padded_line;
	size_t		line_width;

	if (map == NULL || line == NULL)
		return ;
	padded_line = NULL;
	line_width = ft_strlen(line);
	if (ft_strchr(line, '\n') != NULL)
		--line_width;
	if (line_width < map->width)
	{
		padded_line = ft_calloc(map->width + 1, sizeof(char));
		if (padded_line == NULL)
			return ;
		ft_strlcpy(padded_line, line, line_width + 1);
		ft_memset(padded_line + line_width, ' ', (map->width - line_width));
		map->map[line_n] = padded_line;
	}
	else if (padded_line == NULL && line_width == map->width)
		map->map[line_n] = ft_strdup(line);
	if (map->map[line_n] == NULL)
		return ;
}

/**
 * @brief Parse the player's starting position and direction from the map
 * @param map Pointer to the map structure
 * @param line_n The current line number being parsed
 */
static void	ft_parse_player(t_map *map, int line_n)
{
	const char	*g_dirs[] = {"NO", "SO", "WE", "EA"};
	size_t		col;
	t_dir		dir;

	col = 0;
	dir = INVALID;
	while (col < map->width)
	{
		while (++dir <= EAST)
		{
			if (ft_strncmp(map->map[line_n] + col,
					g_dirs[dir], 1) == 0)
			{
				map->map[line_n][col] = '0';
				map->start_direction = dir;
				map->start_pos->x = line_n;
				map->start_pos->y = (int)col;
				return ;
			}
		}
		dir = INVALID;
		++col;
	}
}

/**
 * @brief Check if a line is part of the map (contains '0' or '1')
 * @param line The input line to check
 * @return TRUE if the line is part of the map, FALSE otherwise
 */
t_bool	ft_is_map_line(char *line)
{
	int	i;

	if (line == NULL || line[0] == '\0')
		return (FALSE);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (line[i] == '1' || line[i] == '0');
}
