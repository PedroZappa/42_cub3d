/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:46:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 16:04:29 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check_ext(char *file)
{
	char	*pos;

	pos = ft_strrchr(file, '.');
	if (pos == NULL)
		return (FAILURE);
	return (ft_strncmp(pos, ".cub", 5));
}

int	ft_parse_map(t_cube *cube, char *file)
{
	int	fd;

	if (ft_check_ext(file))
		return (ft_err(EXT_ERR));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	(void)cube;
	close(fd);
	return (SUCCESS);
}
