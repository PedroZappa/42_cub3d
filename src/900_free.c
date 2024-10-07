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

void	ft_vfree(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

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
