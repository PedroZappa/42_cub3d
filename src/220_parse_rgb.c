/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   220_parse_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:35:18 by passunca          #+#    #+#             */
/*   Updated: 2024/10/01 11:36:59 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check_rgb(char *line)
{
	if (ft_strnstr(line, "F", ft_strlen("F"))
		|| ft_strnstr(line, "C", ft_strlen("C")))
		return (!SUCCESS);
	else
		return (ft_err(FILE_ERR), !FAILURE);
}

int	ft_parsing_rgb(char *line, t_map *map)
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
