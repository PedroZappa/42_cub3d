/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   300_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:27:22 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/11 20:34:37 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_img	*ft_init_frame(void *mlx_ptr);

/**
 * @brief Initialize the MLX structure
 * @return Pointer to the initialized MLX structure, or NULL if init fails
 */
t_mlx	*ft_mlx_init(void)
{
	t_mlx	*ret;

	ret = ft_calloc(1, sizeof(t_mlx));
	if (ret == NULL)
		return (NULL);
	ret->ptr = mlx_init();
	if (ret->ptr == NULL)
		return (ft_vfree(ret), NULL);
	ret->frame = ft_init_frame(ret->ptr);
	return (ret);
}

/**
 * @brief Initialize a frame image
 * @param mlx_ptr Pointer to the MLX instance
 * @return Pointer to the initialized image structure, or NULL if init fails
 */
static t_img	*ft_init_frame(void *mlx_ptr)
{
	t_img	*ret;

	ret = ft_calloc(1, sizeof(t_img));
	if (ret == NULL)
		return (NULL);
	ret->img = mlx_new_image(mlx_ptr, WINDOW_W, WINDOW_H);
	if (ret->img == NULL)
		return (ft_vfree(ret), NULL);
	ret->pix = mlx_get_data_addr(ret->img, &ret->bpp,
			&ret->line_len, &ret->endian);
	if (ret->pix == NULL)
		return (mlx_destroy_image(mlx_ptr, ret->img),
			ft_vfree(ret), NULL);
	return (ret);
}

/**
 * @brief Create a new MLX window
 * @param cub Pointer to the main game structure
 * @return SUCCESS if window creation is successful, FAILURE otherwise
 */
int	ft_mlx_new_window(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return (FAILURE);
	cub->mlx->wdw = mlx_new_window(cub->mlx->ptr,
			WINDOW_W, WINDOW_H, WINDOW_TITLE);
	if (cub->mlx->wdw == NULL)
		return (FAILURE);
	return (ft_mlx_set_hooks(cub));
}

/**
 * @brief Set up MLX hooks for keyboard, window closing, and game loop
 * @param cub Pointer to the main game structure
 * @return SUCCESS if hooks are set successfully, FAILURE otherwise
 */
int	ft_mlx_set_hooks(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return (FAILURE);
	mlx_key_hook(cub->mlx->wdw, ft_hook_kb, cub);
	mlx_hook(cub->mlx->wdw, ClientMessage,
		StructureNotifyMask, ft_hook_quit, cub);
	cub->start_time = ft_timestamp();
	mlx_loop_hook(cub->mlx->ptr, ft_loop_hook, cub);
	return (SUCCESS);
}

/**
 * @brief Free all resources associated with the MLX structure
 * @param mlx Pointer to the MLX structure to be freed
 */
void	ft_mlx_free(t_mlx *mlx)
{
	if (mlx == NULL)
		return ;
	if (mlx->wdw != NULL)
		mlx_destroy_window(mlx->ptr, mlx->wdw);
	ft_image_destroy(mlx->frame, mlx->ptr);
	mlx_destroy_display(mlx->ptr);
	ft_vfree(mlx->ptr);
	ft_bzero(mlx, sizeof(t_mlx));
	free(mlx);
}
