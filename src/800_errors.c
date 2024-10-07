/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   800_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:41:19 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/26 20:20:51 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_err(char	*msg)
{
	printf("Error\n%s\n", msg);
	return (FAILURE);
}

int	ft_file_err(char *file)
{
	printf("Error\n");
	printf(FILE_ERR, file);
	printf("\n");
	return (FAILURE);
}

int	ft_parse_err(char *msg)
{
	printf("Error\nThere was a problem while parsing the map: %s\n", msg);
	return (FAILURE);
}

int	ft_parse_size_err(t_bool width, size_t expected, size_t got)
{
	printf("Error\nThere was a problem while parsing the map: %s\n",
		PARSE_SIZE);
	if (width)
		printf("width");
	else
		printf("height");
	printf(" | expected %lu -> has %lu\n", expected, got);
	return (FAILURE);
}
