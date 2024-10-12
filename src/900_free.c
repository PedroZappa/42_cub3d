/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   900_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:04:05 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 14:22:48 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Safely free a pointer
 * @param ptr Pointer to be freed
 * @return None
 * @details
 * This function checks if the pointer is not NULL before freeing it,
 * preventing potential errors from freeing a NULL pointer.
 */
void	ft_vfree(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

/**
 * @brief Free a 2D array of strings
 * @param arr Pointer to the array of strings to be freed
 * @return None
 * @details
 * This function iterates through the array, freeing each string,
 * and then frees the array itself. It safely handles NULL input.
 */
void	ft_free_arr(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

/**
 * @brief Free a 2D array of void pointers
 * @param arr Pointer to the array of void pointers to be freed
 * @return None
 * @details
 * This function iterates through the array, freeing each pointer,
 * and then frees the array itself. It safely handles NULL input.
 */
void	ft_vfree_arr(void **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

/**
 * @brief Free a line and clear the remaining lines from get_next_line
 * @param line Pointer to the current line to be freed
 * @param fd File descriptor to clear remaining lines from
 * @return None
 * @details
 * This function frees the current line and then reads and frees all
 * remaining lines from the given file descriptor using get_next_line.
 * It's useful for cleaning up after encountering an error during file reading.
 */
void	ft_free_gnl(char *line, int fd)
{
	char	*ln;

	ft_free(line);
	if (fd < -1)
		return ;
	ln = get_next_line(fd);
	while (ln)
	{
		ft_free(ln);
		ln = get_next_line(fd);
	}
}
