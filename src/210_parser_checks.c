/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   210_check_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:54:05 by passunca          #+#    #+#             */
/*   Updated: 2024/09/28 18:54:18 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check_ext(char *file)
{
	char	*pos;

	pos = ft_strrchr(file, '.');
	if (pos == NULL)
		return (FAILURE);
	return (ft_strncmp(pos, ".cub", 5));
}

int	ft_check_header(t_map *map)
{
	if (map->paths[0] && map->floor_color.b >= 0 && map->ceiling_color.b >= 0)
		return (!SUCCESS);
	return (!FAILURE);
}

int	ft_check_dir(char *line)
{
	return (ft_strnstr(line, g_dirs[NORTH], ft_strlen(g_dirs[NORTH]))
		|| ft_strnstr(line, g_dirs[SOUTH], ft_strlen(g_dirs[SOUTH]))
		|| ft_strnstr(line, g_dirs[WEST], ft_strlen(g_dirs[WEST]))
		|| ft_strnstr(line, g_dirs[EAST], ft_strlen(g_dirs[EAST])));
}
