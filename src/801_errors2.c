/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   801_erros2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:47:36 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 13:50:33 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Print an error message for duplicate texture definitions
 * @param dir The direction (NO, SO, WE, EA) of the duplicate texture.
 * @return FAILURE(Always returns FAILURE to indicate an error occurred)
 * @details
 * This function prints an error message when a duplicate texture definition is
 * encountered during map parsing. If a specific direction is provided, it 
 * includes this in the message for more detailed error reporting.
 */
int	ft_texture_dupl_err(const char *dir)
{
	printf("Error\nThere was a problem while parsing the map: ");
	if (dir)
		printf("Duplicate '%s' texture definition\n", dir);
	else
		printf("Duplicate texture definition\n");
	return (FAILURE);
}

/**
 * @brief Print an error message for duplicate color definitions
 * @param type Type of color (e.g., "floor" or "ceiling") that's duplicated
 * @return FAILURE(Always returns FAILURE to indicate an error occurred)
 * @details
 * This function prints an error message when a duplicate color definition is
 * encountered during map parsing. If a specific color type is provided,
 * it includes this in the message for more detailed error reporting.
 */
int	ft_color_err(char *type)
{
	printf("Error\nThere was a problem while parsing the map: ");
	if (type)
		printf("Duplicate %s color definition\n", type);
	else
		printf("Duplicate color definition\n");
	return (FAILURE);
}
