/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:59:54 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 14:37:02 by gfragoso         ###   ########.fr       */
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

# define ARG_ERR "Missing map argument\n\
Usage: ./cube3D <path to map file .cub>"
# define EXT_ERR "Map file must have '.cub' extension"
# define FILE_ERR "Could not open file '%s'"

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

typedef enum e_dir
{
	INVALID = -1,
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_dir;

typedef struct s_map
{
	int		floor_color;
	int		ceiling_color;

	char	**paths;
	void	**imgs;

	char	**map;
	t_point	*start_pos;
	int		start_direction;
}	t_map;

typedef struct s_cube
{
	t_mlx	*mlx;

	t_map	*map;
	t_point	*current_pos;
}	t_cube;

/** @file 100_map.c */
t_map	*ft_map_init(void);
void	ft_map_free(t_map *map);

/** @file 200_parser.c */
int		ft_parse_map(t_cube *cube, char *file);

/** @file 300_mlx.c */
t_mlx	*ft_mlx_init(int w, int h, char *title);
void	ft_mlx_free(t_mlx *mlx);

/** @file 800_errors.c */
int		ft_err(char	*msg);
int		ft_file_err(char *file);

/** @file 900_free.c */
void	ft_vfree(void *ptr);
void	ft_free_arr(char **arr);
void	ft_vfree_arr(void **arr);

#endif
