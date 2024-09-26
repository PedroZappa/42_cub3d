/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:59:54 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/25 16:26:25 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h> // printf, perror
# include <fcntl.h> // read
# include <unistd.h> // write
# include <stdlib.h> // exit, free, malloc
# include <string.h> // strerror
# include <sys/time.h> // gettimeofday

# include "../lib/mlx/mlx.h"

# include "../lib/libft/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"

// X11 Defines

# define X11_EVENT_CLIENT_MSG	33
# define X11_EVENT_MASK_CLOSE 	131072L // == (1L << 17)

# define X11_ESC				0xff1b
# define X11_UP					0xff52
# define X11_DOWN				0xff54
# define X11_LEFT				0xff51
# define X11_RIGHT				0xff53

// Errors

# define ARG_ERR 		"Missing map argument\n\
Usage: ./cub3D <path to map file .cub>"
# define EXT_ERR 		"Map file must have '.cub' extension"
# define FILE_ERR 		"Could not open file '%s'"
# define MLX_ERR 		"Couldn't initialize mlx"
# define MLX_HOOK_ERR 	"Couldn't set mlx's hooks"

# define PARSE_COLORS	"Invalid colors for ceiling and/or floor"
# define PARSE_DIR		"Invalid starting point and direction"
# define PARSE_PATH		"Could not open 1 or more texture files"
# define PARSE_BORD		"Not fully closed"

// Window settings

# define WINDOW_W 		1280
# define WINDOW_H	 	720
# define WINDOW_TITLE 	"Cub3D"

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_2dpoint
{
	int	x;
	int	y;
}	t_2dpoint;

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
	int			floor_color;
	int			ceiling_color;

	char		**paths;
	void		**imgs;

	char		**map;
	t_2dpoint	*start_pos;
	int			start_direction;
	int			width;
	int			height;
}	t_map;

typedef struct s_cub
{
	t_mlx	*mlx;

	t_map	*map;
	t_point	*current_pos;
	t_point	*orientation;
}	t_cub;

/** @file 000_main.c */
void		ft_cub_free(t_cub *cub);

/** @file 100_map.c */
t_map		*ft_map_init(void);
void		ft_map_free(t_map *map);
char		ft_map_at_i(t_map *map, int x, int y);
char		ft_map_at(t_map *map, t_2dpoint *p);
void		ft_map_destroy_imgs(t_map *map, t_mlx *mlx);

/** @file 105_map_verify.c */
t_map		*ft_map_verify(t_map *map);

/** @file 110_point.c */
t_point		*ft_point_new(double x, double y, double z);
t_point		*ft_point_copy(t_point *point);
t_2dpoint	*ft_2dpoint_new(int x, int y);
t_2dpoint	*ft_2dpoint_copy(t_2dpoint *point);
t_point		*ft_point_dir(t_dir dir);

/** @file 200_parser.c */
int			ft_parse_map(t_cub *cub, char *file);

/** @file 300_mlx.c */
t_mlx		*ft_mlx_init(int w, int h, char *title);
void		ft_mlx_free(t_mlx *mlx);
int			ft_mlx_set_hooks(t_cub *cub);

/** @file 310_mlx_hooks.c */
int			ft_hook_quit(t_cub *cub);
int			ft_hook_kb(int keycode, t_cub *cub);

/** @file 800_errors.c */
int			ft_err(char	*msg);
int			ft_file_err(char *file);
int			ft_parse_err(char *msg);

/** @file 900_free.c */
void		ft_vfree(void *ptr);
void		ft_free_arr(char **arr);
void		ft_vfree_arr(void **arr);

#endif
