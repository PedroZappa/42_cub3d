/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   720_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:36:12 by passunca          #+#    #+#             */
/*   Updated: 2024/09/28 18:36:15 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_parse_rgb(char *line, t_rgb *rgb)
{
	while (!ft_isdigit(*line))
		++line;
	rgb->r = ft_atoi(line);
	while (ft_isdigit(*line))
		++line;
	while (!ft_isdigit(*line))
		++line;
	rgb->g = ft_atoi(line);
	while (ft_isdigit(*line))
		++line;
	while (!ft_isdigit(*line))
		++line;
	rgb->b = ft_atoi(line);
	return (SUCCESS);
}
