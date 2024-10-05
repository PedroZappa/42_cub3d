/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   240_parse_headers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:17:01 by passunca          #+#    #+#             */
/*   Updated: 2024/10/05 15:25:19 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_parse_headers(char *line, t_map *map)
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
