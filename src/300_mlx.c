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

t_mlx	*ft_mlx_init(int w, int h, char *title)
{
	t_mlx	*ret;

	if (title == NULL)
		return (NULL);
	ret = malloc(sizeof(t_mlx));
	if (ret == NULL)
		return (NULL);
	ret->ptr = mlx_init();
	if (ret->ptr == NULL)
		return (ft_vfree(ret), NULL);
	ret->wdw = mlx_new_window(ret->ptr, w, h, title);
	if (ret->wdw == NULL)
		return (ft_vfree(ret->ptr), ft_vfree(ret), NULL);
	return (ret);
}

int	ft_mlx_set_hooks(t_cub *cub)
{
	if (cub == NULL || cub->mlx == NULL)
		return (FAILURE);
	mlx_key_hook(cub->mlx->wdw, ft_hook_kb, cub);
	mlx_hook(cub->mlx->wdw, X11_EVENT_CLIENT_MSG,
		X11_EVENT_MASK_CLOSE, ft_hook_quit, cub);
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
	mlx->wdw = NULL;
	mlx_destroy_display(mlx->ptr);
	ft_vfree(mlx->ptr);
	mlx->ptr = NULL;
	free(mlx);
}
