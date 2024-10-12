/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   740_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:32:53 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/12 15:28:29 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_image_create(t_tex *tex, void *mlx_ptr, char *fname);

int	ft_load_images(t_mlx *mlx, t_map *map)
{
	int		i;

	if (map == NULL)
		return (FAILURE);
	i = NORTH;
	while (i <= EAST)
	{
		if (map->paths[i] == NULL)
			return (FAILURE);
		if (ft_image_create(&map->tex[i], mlx->ptr, map->paths[i]))
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}

static int	ft_image_create(t_tex *tex, void *mlx_ptr, char *fname)
{
	if (tex == NULL || fname == NULL)
		return (FAILURE);
	tex->img = ft_calloc(1, sizeof(t_img));
	if (tex->img == NULL)
		return (FAILURE);
	tex->img->img = mlx_xpm_file_to_image(mlx_ptr, fname,
			&tex->width, &tex->height);
	if (tex->img->img == NULL)
		return (FAILURE);
	tex->img->pix = mlx_get_data_addr(tex->img->img,
			&tex->img->bpp, &tex->img->line_len,
			&tex->img->endian);
	return (tex->img->pix == NULL);
}

void	ft_image_destroy(t_img *img, void *mlx_ptr)
{
	if (img == NULL || mlx_ptr == NULL)
		return ;
	if (img->img)
		mlx_destroy_image(mlx_ptr, img->img);
	ft_bzero(img, sizeof(t_img));
	free(img);
}
