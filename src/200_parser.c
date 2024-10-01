/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:46:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/28 18:52:57 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		ft_measure_map(int fd);
static t_map	*ft_parse_loop(int fd, int map_height);
static int		ft_parsing_map(char *line, t_map *map);
static void		ft_parse_header(char *line, t_map *map);
static int		ft_parsing_colors(char *line, t_map *map);

int	ft_parse_map(t_cub *cub, char *file)
{
	int	fd;

	if (ft_check_ext(file))
		return (ft_err(EXT_ERR));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	cub->map->height = ft_measure_map(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	cub->map = ft_parse_loop(fd, cub->map->height);
	if (cub->map != NULL)
		cub->map = ft_map_verify(cub->map);
	if (cub->map != NULL && !SKIP_VERIFY)
	{
		cub->current_pos = ft_vec_new(cub->map->start_pos->x,
				cub->map->start_pos->y, WINDOW_H / 2);
		cub->orientation = ft_vec_dir(cub->map->start_direction);
	}
	return (close(fd), cub->map == NULL);
}

static int	ft_measure_map(int fd)
{
	int		map_height;
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, '1') != NULL)
		{
			if (line[0] != '\0')
				++map_height;
			ft_free(line);
			line = get_next_line(fd);
		}
	}
	return (close(fd), map_height);
}

static t_map	*ft_parse_loop(int fd, int map_height)
{
	t_map	*map;
	char	*line;
	int		parsing_map;

	map = ft_map_init();
	if (map == NULL)
		return (NULL);
	parsing_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if ((ft_strchr(line, '1') != NULL) && (ft_strncmp(line, "1", 1) == 0))
			parsing_map = 1;
		if (parsing_map && ft_parsing_map(line, map))
			return (ft_err(FILE_ERR), NULL);
		else
			ft_parse_header(line, map);
		ft_free(line);
		line = get_next_line(fd);
	}
	return (ft_free(line), map);
}

static void	ft_parse_header(char *line, t_map *map)
{
	static const char	*dir_str[] = {"NO", "SO", "WE", "EA"};
	char				*nl;
	t_dir				dir;

	if (map == NULL || line == NULL)
		return ;
	dir = INVALID;
	while (ft_isspace(*line))
		++line;
	while (++dir <= EAST)
	{
		if (ft_strncmp(line, dir_str[dir], 2) == 0)
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
		ft_parsing_colors(line, map);
}

static int	ft_parsing_colors(char *line, t_map *map)
{
	if (map == NULL || line == NULL)
		return (ft_err(FILE_ERR), FAILURE);
	while (ft_isspace(*line))
		++line;
	if (ft_strncmp(line, "F", 1) == 0)
		ft_parse_rgb(line, &map->floor_color);
	else if (ft_strncmp(line, "C", 1) == 0)
		ft_parse_rgb(line, &map->ceiling_color);
	return (SUCCESS);
}

static int	ft_parsing_map(char *line, t_map *map)
{
	if (map == NULL || line == NULL)
		return (ft_err(FILE_ERR), FAILURE);
	while (ft_isspace(*line))
		++line;
	// TODO : Parse Map
	return (SUCCESS);
}
