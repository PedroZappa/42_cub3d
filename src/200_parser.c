/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:46:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/01 11:47:08 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_map	*ft_measure_map(int fd, t_map *map);
static t_map	*ft_parse_loop(int fd, t_map *map);
static int		ft_check_dir(char *line);
static void		ft_parse_headers(char *line, t_map *map);

const char	*g_dirs[] = {"NO", "SO", "WE", "EA"};

int	ft_parse_map(t_cub *cub, char *file)
{
	t_map	*map;
	int		fd;

	if (ft_check_ext(file))
		return (ft_err(EXT_ERR));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	map = ft_map_init();
	if (map == NULL)
		return (0);
	map = ft_measure_map(fd, map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	map = ft_parse_loop(fd, map);
	cub->map = map;
	if (cub->map != NULL)
		cub->map = ft_map_verify(cub->map);
	if (cub->map != NULL && !SKIP_VERIFY)
	{
		cub->current_pos = ft_vec_new(
				cub->map->start_pos->x, cub->map->start_pos->y, WINDOW_H / 2);
		cub->orientation = ft_vec_dir(cub->map->start_direction);
	}
	return (close(fd));
}

static t_map	*ft_parse_loop(int fd, t_map *map)
{
	char	*line;

	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (map->map == NULL)
		return (ft_map_free(map), NULL);
	map->map[map->height] = NULL;
	map->start_pos = malloc(sizeof(t_point));
	if (map->start_pos == NULL)
		return (ft_map_free(map), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_check_dir(line))
			ft_parse_headers(line, map);
		else if (ft_check_rgb(line))
			ft_parsing_rgb(line, map);
		else if (ft_strchr(line, '1') != NULL)
			ft_parsing_map(line, map);
		ft_free(line);
		line = get_next_line(fd);
	}
	return (ft_free(line), map);
}

static t_map	*ft_measure_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '1') != NULL)
		{
			if (line[0] != '\0')
				++map->height;
		}
		ft_free(line);
		line = get_next_line(fd);
	}
	return (close(fd), map);
}

static int	ft_check_dir(char *line)
{
	if (ft_strnstr(line, g_dirs[NORTH], ft_strlen(g_dirs[NORTH]))
		|| ft_strnstr(line, g_dirs[SOUTH], ft_strlen(g_dirs[SOUTH]))
		|| ft_strnstr(line, g_dirs[WEST], ft_strlen(g_dirs[WEST]))
		|| ft_strnstr(line, g_dirs[EAST], ft_strlen(g_dirs[EAST])))
		return (!SUCCESS);
	else
		return (ft_err(FILE_ERR), !FAILURE);
}

static void	ft_parse_headers(char *line, t_map *map)
{
	char	*nl;
	t_dir	dir;

	if (map == NULL || line == NULL)
		return ;
	dir = INVALID;
	while (ft_isspace(*line))
		++line;
	while (++dir <= EAST)
	{
		if (ft_strncmp(line, g_dirs[dir], 2) == 0)
		{
			line += 2;
			while (ft_isspace(*line))
				++line;
			nl = ft_strchr(line, '\n');
			if (nl != NULL)
				*nl = '\0';
			map->paths[dir] = ft_strdup(line);
			return ;
		}
	}
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		ft_parsing_rgb(line, map);
}
