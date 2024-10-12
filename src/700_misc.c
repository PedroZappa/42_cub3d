/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   700_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:37 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:24:37 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Get the current timestamp in milliseconds
 * @return The current timestamp in milliseconds, or -1 if an error occurs
 * @details
 * This function uses gettimeofday to get the current time and converts it 
 * to milliseconds.
 */
long	ft_timestamp(void)
{
	struct timeval	tm;

	if (gettimeofday(&tm, NULL))
		return (-1);
	return ((tm.tv_sec * 1000) + (tm.tv_usec * 0.001));
}

/**
 * @brief Check if a file has the correct extension (.cub)
 * @param file The filename to check
 * @return SUCCESS if the file has the correct extension, FAILURE otherwise
 * @details
 * This function checks if the given filename ends with ".cub" and ensures
 * it's a valid filename.
 */
int	ft_check_ext(char *file)
{
	char	*pos;

	pos = ft_strrchr(file, '.');
	if (pos == NULL || file == pos
		|| *(pos - 1) == '/')
		return (FAILURE);
	return (ft_strncmp(pos, ".cub", 5));
}

/**
 * @brief Convert RGB color components to a single integer representation
 * @param rgb The RGB color structure containing red, green, and blue components
 * @return The color as a single integer value
 * @details
 * This function combines the red, green, and blue color components into a single
 * 32-bit integer.
 */
int	ft_rgb_to_int(t_rgb rgb)
{
	return (((rgb.r & 0xFF) << 16)
		| ((rgb.g & 0xFF) << 8)
		| (rgb.b & 0xFF));
}
