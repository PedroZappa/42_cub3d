/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   710_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:48 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/07 14:24:48 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Create a new t_point structure
 * @param x The x-coordinate of the point
 * @param y The y-coordinate of the point
 * @return SUCCESS(Pointer to the newly created t_point structure)
 * @return FAILURE(NULL if allocation fails)
 * @details
 * This function allocates memory for a new t_point structure and initializes
 * it with the given x and y coordinates.
 */
t_point	*ft_point_new(int x, int y)
{
	t_point	*ret;

	ret = malloc(sizeof(t_point));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	return (ret);
}

/**
 * @brief Create a copy of a t_point structure
 * @param point Pointer to the t_point structure to be copied
 * @return SUCCESS(Pointer to the newly created copy of the t_point structure)
 * @return FAILURE(NULL if allocation fails)
 * @details
 * This function creates a new t_point structure with the same x and y
 * coordinates as the input point.
 */
t_point	*ft_point_copy(t_point *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_point_new(point->x, point->y));
}
