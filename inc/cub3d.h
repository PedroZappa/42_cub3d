/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:59:54 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 13:29:45 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> // exit, free, malloc
# include <stdio.h> // printf, perror
# include <fcntl.h> // read
# include <unistd.h> // write
# include <string.h> // strerror
# include <sys/time.h> // gettimeofday
# include <math.h>

# include "../lib/libft/libft/libft.h"
# include "../lib/mlx/mlx.h"

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_mlx
{
	void	*ptr;
	void	*wdw;
}	t_mlx;

typedef struct s_map
{
	
}	t_map;

typedef struct s_cube
{
	t_mlx	*mlx;
}	t_cube;

#endif
