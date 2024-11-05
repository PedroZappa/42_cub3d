/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:46:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 19:27:19 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_map	*ft_parse_init(int *fd, char *file);
static t_map	*ft_measure_map(int fd, t_map *map);
static t_map	*ft_parse_loop(int fd, t_map *map);
static int		ft_parse_line(char *line, t_map *map, int *mode);

/**
 * @brief Parse the map file and initialize Cub3d data structure
 * @param cub Pointer to a t_cub struct
 * @param file Path to the map file
 * @return SUCCESS(if parsing was successful)
 * @return FAILURE(otherwise)
 */
int	ft_parse_map(t_cub *cub, char *file)
{
	t_map	*map;
	int		fd;

	if (ft_check_ext(file))
		return (ft_err(EXT_ERR));
	map = ft_parse_init(&fd, file);
	if (map == NULL)
		return (FAILURE);
	map = ft_parse_loop(fd, map);
	if (map == NULL)
		return (close(fd), FAILURE);
	cub->map = map;
	if (cub->map != NULL)
		cub->map = ft_map_verify(cub->map);
	if (cub->map == NULL)
		return (close(fd), FAILURE);
	cub->pos = ft_vec_new(cub->map->start_pos->x + 0.5,
			cub->map->start_pos->y + 0.5);
	ft_vec_dir(cub, cub->map->start_direction);
	return (close(fd), SUCCESS);
}

/**
 * @brief Initialize the map parsing process
 * @param fd Pointer to the file descriptor
 * @param file Path to the map file
 * @return SUCCES(Pointer to the initialized t_map struct)
 * @return FAILURE(NULL)
 */
static t_map	*ft_parse_init(int *fd, char *file)
{
	t_map	*map;

	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (ft_file_err(file), NULL);
	map = ft_map_init();
	if (map == NULL)
		return (close(*fd), ft_err(PARSE_INIT_ERR), NULL);
	map = ft_measure_map(*fd, map);
	close(*fd);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	return (map);
}

/**
 * @brief Main loop for parsing the map file
 * @param fd File descriptor of the opened map file
 * @param map Pointer to the t_map structure
 * @return SUCCESS(Updated map structure)
 * @return FAILURE(NULL)
 */
static t_map	*ft_parse_loop(int fd, t_map *map)
{
	char		*line;
	int			mode;

	map->map = ft_calloc(map->height + 1, sizeof(char *));
	if (map->map == NULL)
		return (ft_map_free(map), NULL);
	map->start_pos = ft_calloc(1, sizeof(t_point));
	if (map->start_pos == NULL)
		return (ft_map_free(map), NULL);
	line = get_next_line(fd);
	mode = 0;
	while (line)
	{
		if (ft_parse_line(line, map, &mode))
			return (ft_free_gnl(line, fd), ft_map_free(map), NULL);
		ft_free(line);
		line = get_next_line(fd);
	}
	return (ft_free(line), map);
}

/**
 * @brief Parse a single line from the map file
 * @param line The line to be parsed
 * @param map Pointer to the map structure
 * @param mode Pointer to the parsing mode (0 for headers, 1 for map)
 * @return SUCCESS(0, if parsing was successful)
 * @return FAILURE(1)
 */
static int	ft_parse_line(char *line, t_map *map, int *mode)
{
	if (mode == NULL)
		return (FAILURE);
	if (ft_is_map_line(line))
	{
		if (*mode == 0)
			*mode = 1;
		return (ft_parsing_map(line, map));
	}
	if (*mode == 1)
		return (ft_parse_err(PARSE_WRG_ORDR), FAILURE);
	return (ft_parse_headers(line, map));
}

/**
 * @brief Measure the width and height of the map
 * @param fd File descriptor of the opened map file
 * @param map Pointer to the t_map structure
 * @return SUCCESS(Updated map structure)
 * @return FAILURE(NULL)
 */
static t_map	*ft_measure_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_is_map_line(line))
		{
			map->width
				= ft_max(map->width, ft_strlen(line));
			++map->height;
		}
		ft_free(line);
		line = get_next_line(fd);
	}
	return (close(fd), map);
}
