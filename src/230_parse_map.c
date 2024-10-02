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

/*void	ft_fillw(char **line, size_t size, char c)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = ft_strlen(*line);
	ret = ft_calloc(j + size + 1, sizeof(char));
	if (ret == NULL)
	 return ;
	i = -1;
	while (line[0][++i])
		ret[i] = line[0][i];
	while (++i < j + size)
		ret[i] = c;
	ret[++i] = '\0';
	ft_free(*line);
	*line = ret;
	printf("%s %lu\n", *line, size);
}*/

int	ft_parsing_map(char *line, t_map *map)
{
	static int	line_count = 0;
	size_t		line_width;

	if (map == NULL || line == NULL)
		return (ft_err(PARSE_ERR));
	if (ft_isalpha(line[0]))
		return (FAILURE);
	map->map[line_count] = ft_strdup(line);
	if (map->map[line_count] == NULL)
		return (ft_err(MEM_ERR));
	line_width = ft_strlen(line);
	ft_parse_player(line, map);
	++line_count;
	return (SUCCESS);
}

static void	ft_parse_player(char *line, t_map *map)
{
	static int	curr_line = 0;
	size_t		col;
	t_dir		dir;

	col = 0;
	dir = INVALID;
	while (col < map->width)
	{
		while (++dir <= EAST)
		{
			if (ft_strncmp(line + col, g_dirs[dir], 1) == 0)
			{
				line[col] = '0';
				map->start_direction = dir;
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

t_bool	ft_is_map_line(char *line)
{
	int	i;

	if (line == NULL || line[0] == '\0')
		return (FALSE);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (line[i] == '1');
}
