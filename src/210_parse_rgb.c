/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   210_parse_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:26:07 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:26:07 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_check_rgb(char *line, t_rgb *rgb, char *field);
static int	ft_parse_rgb(char *line, t_rgb *rgb);

/**
 * @brief Parse RGB color values from a line of input
 * @param line The input line containing RGB color information
 * @param map Pointer to the map structure to store the parsed colors
 * @return SUCCESS if parsing is successful, FAILURE otherwise
 */
int	ft_parsing_rgb(char *line, t_map *map)
{
	if (map == NULL || line == NULL)
		return (ft_err(PARSE_ERR), FAILURE);
	while (ft_isspace(*line))
		++line;
	if (ft_strncmp(line, "F", 1) == 0)
		return (ft_check_rgb(line, &map->floor_color, "floor"));
	if (ft_strncmp(line, "C", 1) == 0)
		return (ft_check_rgb(line, &map->ceiling_color, "ceiling"));
	return (SUCCESS);
}

/**
 * @brief Check and parse RGB color values for a specific field
 * @param line The input line containing RGB color information
 * @param rgb Pointer to the RGB structure to store the parsed values
 * @param field String indicating which field is being parsed (e.g., "floor" or "ceiling")
 * @return SUCCESS if parsing is successful, FAILURE otherwise
 */
static int	ft_check_rgb(char *line, t_rgb *rgb, char *field)
{
	if (rgb == NULL)
		return (FAILURE);
	if ((rgb->b == -1) && (rgb->g == -1) && (rgb->r == -1))
	{
		if (ft_parse_rgb(line, rgb))
			return (ft_parse_err(PARSE_CLR_FMT));
		return (SUCCESS);
	}
	return (ft_color_err(field));
}

/**
 * @brief Parse individual RGB color components from a string
 * @param line The input string containing RGB color information
 * @param rgb Pointer to the RGB structure to store the parsed values
 * @return 0 if parsing is successful, non-zero if there's an error
 */
static int	ft_parse_rgb(char *line, t_rgb *rgb)
{
	while (!ft_isdigit(*line))
		++line;
	rgb->r = ft_atoi(line);
	while (ft_isdigit(*line))
		++line;
	if (*line != ',')
		return (FAILURE);
	++line;
	rgb->g = ft_atoi(line);
	while (ft_isdigit(*line))
		++line;
	if (*line != ',')
		return (FAILURE);
	++line;
	rgb->b = ft_atoi(line);
	while (ft_isdigit(*line))
		++line;
	return (*line != '\n');
}
