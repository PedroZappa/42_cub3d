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

int	ft_parsing_map(char *line, t_map *map)
{
	static int	line_count = 0;

	if (map == NULL || line == NULL)
		return (ft_err(FILE_ERR));
	if (ft_isalpha(line[0]))
		return (FAILURE);
	map->map[line_count++] = ft_strdup(line);
	if (map->map == NULL)
		return (ft_err(MEM_ERR));
	return (SUCCESS);
}
