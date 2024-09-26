/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:46:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 23:42:06 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_check_ext(char *file);
t_map	*ft_parse_loop(int fd);
int		ft_parsing_map(char *line, t_map *map);
void	ft_parse_header(char *line, t_map *map);

int	ft_parse_map(t_cub *cub, char *file)
{
	int	fd;

	if (ft_check_ext(file))
		return (ft_err(EXT_ERR));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	cub->map = ft_parse_loop(fd);
	if (cub->map != NULL)
		cub->map = ft_map_verify(cub->map);
	if (cub->map != NULL)
	{
		cub->current_pos = ft_vec_new(cub->map->start_pos->x,
				cub->map->start_pos->y, WINDOW_H / 2);
		cub->orientation = ft_vec_dir(cub->map->start_direction);
	}
	return (close(fd), cub->map == NULL);
}

t_map	*ft_parse_loop(int fd)
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
		if (line[0] == '1')
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

void	ft_parse_header(char *line, t_map *map)
{
	if (map == NULL || line == NULL)
		return ;
	// Parse the header
}

int	ft_parsing_map(char *line, t_map *map)
{
	if (map == NULL || line == NULL)
		return (ft_err(FILE_ERR));
	// Parse the actual map
	return (SUCCESS);
}

int	ft_check_ext(char *file)
{
	char	*pos;

	pos = ft_strrchr(file, '.');
	if (pos == NULL)
		return (FAILURE);
	return (ft_strncmp(pos, ".cub", 5));
}
