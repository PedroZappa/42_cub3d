/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   720_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:24:53 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 21:05:42 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Create a new t_vec structure
 * @param x The x-component of the vector
 * @param y The y-component of the vector
 * @return SUCCESS(Pointer to the newly created t_vec structure)
 * @return FAILURE(NULL if allocation fails)
 * @details
 * This function allocates memory for a new t_vec structure and initializes
 * it with the given x and y components.
 */
t_vec	*ft_vec_new(double x, double y)
{
	t_vec	*ret;

	ret = malloc(sizeof(t_vec));
	if (ret == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	return (ret);
}

/**
 * @brief Create a copy of a t_vec structure
 * @param point Pointer to the t_vec structure to be copied
 * @return SUCCESS(Pointer to the newly created copy of the t_vec structure)
 * @return FAILURE(NULL if allocation fails)
 * @details
 * This function creates a new t_vec structure with the same x and y 
 * components as the input vector.
 */
t_vec	*ft_vec_copy(t_vec *point)
{
	if (point == NULL)
		return (NULL);
	return (ft_vec_new(point->x, point->y));
}

/**
 * @brief Create a unit vector based on a given direction
 * @param dir The direction enum value (NORTH, SOUTH, WEST, or EAST)
 * @return SUCCESS(Pointer to a new t_vec structure representing the unit 
 * vector in the given direction)
 * @retuirn FAILURE(NULL for invalid input)
 * @details
 * This function creates a unit vector pointing in the specified
 * cardinal direction.
 */
void	ft_vec_dir(t_cub *cub, t_dir dir)
{
	if (dir == NORTH)
	{
		cub->orientation = ft_vec_new(-1, 0);
		cub->plane = ft_vec_new(0, PLANE);
	}
	if (dir == SOUTH)
	{
		cub->orientation = ft_vec_new(1, 0);
		cub->plane = ft_vec_new(0, -PLANE);
	}
	if (dir == WEST)
	{
		cub->orientation = ft_vec_new(0, -1);
		cub->plane = ft_vec_new(-PLANE, 0);
	}
	if (dir == EAST)
	{
		cub->orientation = ft_vec_new(0, 1);
		cub->plane = ft_vec_new(PLANE, 0);
	}
}

/**
 * @brief Normalize a vector to unit length
 * @param vec Pointer to the t_vec structure to be normalized
 * @details
 * Modifies the input vec to have a length of 1 while preserving its direction.
 * If the vector has 0 length, no changes are made to avoid division by zero.
 */
void	ft_vec_norm(t_vec *vec)
{
	double	len;

	len = sqrt((vec->x * vec->x) + (vec->y * vec->y));
	if (len != 0)
	{
		vec->x /= len;
		vec->y /= len;
	}
}
