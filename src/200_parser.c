/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   200_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:46:14 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 23:42:06 by gfragoso         ###   ########.fr       */
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

t_map	*ft_parse_loop(int fd)
{
	t_map	*ret;
	char	*str;
	int		parsing_map;

	ret = ft_map_init();
	if (ret == NULL)
		return (NULL);
	parsing_map = 0;
	str = get_next_line(fd);
	while (str)
	{
		// missing actual parsing
		(void)parsing_map;
		ft_free(str);
		str = get_next_line(fd);
	}
	return (ft_free(str), ret);
}

int	ft_parse_map(t_cub *cub, char *file)
{
	int	fd;

	if (ft_check_ext(file))
		return (ft_err(EXT_ERR));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_file_err(file));
	cub->map = ft_parse_loop(fd);
	if (cub->map != NULL)
		cub->map = ft_map_verify(cub->map);
	if (cub->map != NULL)
		cub->current_pos = ft_point_copy(cub->map->start_pos);
	return (close(fd), cub->map == NULL);
}
