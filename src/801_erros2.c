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

int	ft_texture_dupl_err(const char *dir)
{
	printf("Error\nThere was a problem while parsing the map: ");
	if (dir)
		printf("Duplicate '%s' texture definition\n", dir);
	else
		printf("Duplicate texture definition\n");
	return (FAILURE);
}

int	ft_color_err(char *type)
{
	printf("Error\nThere was a problem while parsing the map: ");
	if (type)
		printf("Duplicate %s color definition\n", type);
	else
		printf("Duplicate color definition\n");
	return (FAILURE);
}
