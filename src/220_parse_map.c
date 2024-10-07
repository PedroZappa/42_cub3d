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
				map->start_pos->x = (int)col;
				map->start_pos->y = line_n;
				return ;
			}
		}
		dir = INVALID;
		++col;
	}
}

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
