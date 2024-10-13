/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:59:54 by gfragoso          #+#    #+#             */
/*   Updated: 2024/10/12 11:41:21 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>	// sqrt, fabs
# include <stdio.h> // printf, perror
# include <fcntl.h> // read
# include <unistd.h> // write
# include <stdlib.h> // exit, free, malloc
# include <string.h> // strerror
# include <sys/time.h> // gettimeofday
# include <X11/X.h> // MLX library for Event codes
# include <X11/keysym.h> // Keysym for event handling
# include <stdbool.h> // true false
// # include <float.h> // DBL_MAX

# include "../lib/mlx/mlx.h"

# include "../lib/libft/libft/libft.h"
# include "../lib/libft/get_next_line/get_next_line.h"
# include "../lib/libft/ft_fprintf/ft_fprintf.h"
# include "../lib/libft/ft_printf/ft_printf.h"

# include "../inc/test_syscallz.h"

// Errors

# define ARG_ERR 		"Missing map argument\n\
Usage: ./cub3D <path to map file .cub>"
# define EXT_ERR 		"Map file must have '.cub' extension"
# define FILE_ERR 		"Could not open file '%s'"
# define MLX_ERR 		"Couldn't initialize mlx"
# define MLX_HOOK_ERR 	"Couldn't set mlx's hooks"
# define MEM_ERR		"Couldn't allocate memory"
# define RAYCAST_ERR	"Couldn't initilaize raycaster"
# define LOAD_ERR		"Couldn't load the textures\n\
Note that MLX only supports files in xpm format"

# define PARSE_COLORS	"Invalid colors for ceiling and/or floor"
# define PARSE_DIR		"Invalid starting point and direction"
# define PARSE_PATH		"Could not open 1 or more texture files"
# define PARSE_BORD		"Not fully closed"
# define PARSE_SIZE		"Map array doesn't match its size"
# define PARSE_CONT		"Found invalid character inside map"
# define PARSE_ERR		"Map parsing wasn't successful"
# define PARSE_INIT_ERR	"Map parsing init wasn't successful"
# define PARSE_LOOP_ERR	"Map parsing loop failed"
# define PARSE_INV_LINE "Invalid line"
# define PARSE_WRG_ORDR	"Map is not at the bottom and/or \
has separated sections"
# define PARSE_CLR_FMT	"Color is not formatted correctly"

// Window settings

# define WINDOW_W 		1280
# define WINDOW_H	 	720
# define WINDOW_TITLE 	"Cub3D"

// Camera Settings

# define FOV			60.0

// Constants (aka, Them Magick Numberz)

# define DBL_MAX 1.7976931348623158e+308

// Enums

typedef enum e_coord
{
	X = 0,
	Y
}	t_coord;

typedef enum e_exit
{
	SUCCESS,
	FAILURE
}	t_exit;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_dir
{
	INVALID = -1,
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_dir;

typedef enum e_move
{
	FOWARD,
	LEFT,
	BACKWARDS,
	RIGHT,
}	t_move;

// Structs

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_img
{
	void	*img;
	char	*pix;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_tex
{
	t_img	*img;
	int		width;
	int		height;
}			t_tex;

typedef struct s_mlx
{
	void	*ptr;
	void	*wdw;
	t_img	*frame;
}			t_mlx;

typedef struct s_target
{
	t_point	*pos;
	double	dist;
	double	hitpoint;
	double	tile_offset;
	int		tex_x;
	int		wall_height;
	int		wall_bottom;
	int		wall_top;
	t_dir	wall_dir;
}			t_target;

/**
 * @param map Ray coordinates in the map
 * @param pos Camera's position in the map
 * @param vec_dir Camera's directional vector
 * @param ray_dir Ray's directional vector
 * @param delta_dist Distance to the next grid boundary
 * @param small_delta Initial distance to the first grid boundary
 * @param step Direction to step in the grid (-1 or 1)
 * @param camera Camera's plane (used to calculate ray directions)
 * @param camera_offset Camera's offset
 * @param center_raylen Length of the ray from the center of the screen
 **/
typedef struct s_ray
{
	t_point		*map;
	t_vec		*pos;
	t_vec		*vec_dir;
	t_vec		*ray_dir;

	t_vec		*delta_dist;
	t_vec		*small_delta;
	t_point		*step;

	t_vec		*camera;
	t_vec		*camera_offset;
	double		center_raylen;
}				t_ray;

// paths/imgs : NO, SO, WE, EA
typedef struct s_map
{
	char		**paths;
	t_tex		tex[4];

	t_rgb		floor_color;
	t_rgb		ceiling_color;

	char		**map;
	t_point		*start_pos;
	t_dir		start_direction;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct s_cub
{
	t_mlx		*mlx;

	t_map		*map;
	t_ray		*ray;
	t_vec		*current_pos;
	t_vec		*orientation;

	long		start_time;
	double		frame_time;
}				t_cub;

// Functions

/** @file 000_main.c */
void		ft_cub_free(t_cub *cub);

/** @file 100_map.c */
t_map		*ft_map_init(void);
void		ft_map_free(t_map *map);
void		ft_map_destroy_imgs(t_map *map, t_mlx *mlx);

/** @file 101_map_at.c */
char		ft_map_at_i(t_map *map, int x, int y);
char		ft_map_at(t_map *map, t_point *p);
char		*ft_map_at_i_ref(t_map *map, int x, int y);
char		*ft_map_at_ref(t_map *map, t_point *p);

/** @file 110_map_verify.c */
t_map		*ft_map_verify(t_map *map);

/** @file 111_map_verify.c */
int			ft_verify_borders(t_map *map);

/** @file 200_parser.c */
int			ft_parse_map(t_cub *cub, char *file);

/** @file 210_parse_rgb.c */
int			ft_parsing_rgb(char *line, t_map *map);

/** @file 220_parse_map.c */
int			ft_parsing_map(char *line, t_map *map);
t_bool		ft_is_map_line(char *line);

/** @file 230_parse_headers.c */
int			ft_parse_headers(char *line, t_map *map);

/** @file 300_mlx.c */
t_mlx		*ft_mlx_init(void);
void		ft_mlx_free(t_mlx *mlx);
int			ft_mlx_set_hooks(t_cub *cub);
int			ft_mlx_new_window(t_cub *cub);

/** @file 310_mlx_hooks.c */
int			ft_hook_quit(t_cub *cub);
int			ft_hook_kb(int keycode, t_cub *cub);
int			ft_loop_hook(t_cub *cub);

/** @file 400_renderer.c */
void		ft_render(t_cub *cub);

/** @file 410_pixel.c */
void		ft_pixel_put(t_img *img, int x, int y, int color);

/** @file 420_ui.c */
void		ft_render_fps(t_cub *cub);

/** @file 500_raycaster.c */
void		ft_get_ray(t_cub *cub, int x);

/** @file 510_itersect.c */
void		ft_get_intersection(t_cub *cub, t_target *target);

/** @file 700_misc.c */
long		ft_timestamp(void);
int			ft_check_ext(char *file);
int			ft_rgb_to_int(t_rgb rgb);

/** @file 710_point.c */
t_point		*ft_point_new(int x, int y);
t_point		*ft_point_copy(t_point *point);

/** @file 720_vec.c */
t_vec		*ft_vec_new(double x, double y);
t_vec		*ft_vec_copy(t_vec *point);
t_vec		*ft_vec_dir(t_dir dir);
void		ft_vec_norm(t_vec *vec);

/** @file 730_raycast.c */
t_ray		*ft_ray_init(t_point *start_pos, t_dir start_dir);
void		ft_ray_free(t_ray *ray);

/** @file 740_image.c */
int			ft_load_images(t_mlx *mlx, t_map *map);
void		ft_image_destroy(t_img *img, void *mlx_ptr);

/** @file 800_errors.c */
int			ft_err(char	*msg);
int			ft_file_err(char *file);
int			ft_parse_err(char *msg);
int			ft_parse_size_err(t_bool width, size_t expected, size_t got);

/** @file 801_errors2.c */
int			ft_color_err(char *type);
int			ft_texture_dupl_err(const char *dir);

/** @file 900_free.c */
void		ft_vfree(void *ptr);
void		ft_free_arr(char **arr);
void		ft_vfree_arr(void **arr);
void		ft_free_gnl(char *line, int fd);

#endif
