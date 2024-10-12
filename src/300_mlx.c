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
#include <X11/X.h>

static t_img	*ft_init_frame(void *mlx_ptr);

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
