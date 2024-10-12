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

/**
 * @brief Load texture images for Cub3d
 * @param mlx Pointer to the MLX structure
 * @param map Pointer to the map structure containing texture paths
 * @return SUCCESS(0 if all images are loaded successfully)
 * @return FAILURE(Non-zero if any image fails to load)
 * @details
 * This function loads texture images for each direction (NORTH, SOUTH, WEST, EAST)
 * using the paths stored in the map structure. It uses the MLX library to create
 * image structures from XPM files.
 */
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

/**
 * @brief Create an image structure from an XPM file
 * @param tex Pointer to the texture structure to be filled
 * @param mlx_ptr Pointer to the MLX instance
 * @param fname Filename of the XPM image to load
 * @return SUCCESS(0 if the image is created successfully)
 * @return FAILURE(Non-zero if any step of image creation fails)
 * @details
 * This function creates an MLX image structure from an XPM file. It allocates
 * memory for the image structure, loads the XPM file, and retrieves the image
 * data address. The resulting image is stored in the provided texture structure.
 */
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

/**
 * @brief Destroy an MLX image and free associated memory
 * @param img Pointer to the image structure to be destroyed
 * @param mlx_ptr Pointer to the MLX instance
 * @return None
 * @details
 * This function safely destroys an MLX image, frees the associated memory,
 * and zeroes out the image structure before freeing it. It handles NULL
 * inputs safely to prevent errors.
 */
void	ft_image_destroy(t_img *img, void *mlx_ptr)
{
	if (img == NULL || mlx_ptr == NULL)
		return ;
	if (img->img)
		mlx_destroy_image(mlx_ptr, img->img);
	ft_bzero(img, sizeof(t_img));
	free(img);
}
