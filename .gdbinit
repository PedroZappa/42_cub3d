### GDB Settings
set prompt (zdb) 
set editing on
# set verbose on
set tui border-kind acs
set tui active-border-mode bold-standout
set tui border-mode reverse
set trace-commands on
set logging enabled on
set follow-fork-mode child
# set detach-on-fork off

show follow-fork-mode

set print pretty on
# set print elements 2
set print array on
set print array-indexes on

### 000_main.c
define main
	display argc
	display *argv@argc
	display cub
  display *cub->map->paths@4
  display *cub->map->imgs@4
  display cub->map->ceiling_color
  display cub->map->floor_color
  display *cub->map->map@cub->map->height
  display cub->map->start_pos
  display cub->map->start_direction
  display cub->map->width
  display cub->map->height
end

# 105_map_verify.c
define map_verify
	display *map
	display *map->paths@4
	display *map->imgs@4
	display map->map[i]
	display i
	display len
end

### 200_parser.c
define parse_map
  display cub
  display cub->map
  display *cub->map->paths@4
  display *cub->map->imgs@4
  display cub->map->floor_color
  display cub->map->ceiling_color
  display *cub->map->map@cub->map->height
  display cub->map->start_pos->x
  display cub->map->start_pos->y
  display cub->map->start_direction
  display cub->map->width
  display cub->map->height
  display cub->current_pos
  display cub->start_pos->x
  display cub->start_pos->y
  display file
  display fd
end

define parse_loop
  display map
  display *map->paths@4
  display *map->imgs@4
  display map->floor_color
  display map->ceiling_color
  display *map->map@map->height
  display map->start_pos
  display map->start_direction
  display map->width
  display map->height
  display line
end

define parse_line
  display map
  display line
end

define parse_header
  display line
  display map
  display map->paths
  display map->paths[dir]
  display dir
  display dir_str[dir]
end

define measure_map
	display *map
	display map->width
	display map->height
	display fd
	display line
end

define parsing_map
  display map->map[line_count-1]
  display map->map[line_count]
  display map->map[line_count+1]
end

define parse_player
  display line
  display line[col]
  display map
  display map->start_pos->x
  display map->start_pos->y
  display curr_line
  display col
  display dir
end

# 210_parser_checks.c
define parser_checks
	display map
	display map->paths
	display map->paths[0]
	display map->floor_color
	display map->ceiling_color
end

define check_header
	display map->paths@4
	display map->paths[0]
	display map->floor_color
	display map->ceiling_color
end

# 400_renderer.c
define draw_image
	display cub
	display height
	display x
end

# 500_raycaster.c
define computer_ray
  display cub
  display *cub->ray
end

define get_small_delta
  display cub
  display *cub->ray
  display *cub->ray->get_small_delta
  display *cub->ray->step
end

define get_small_delta
  display cub
  display *cub->ray
end

define get_delta
  display cub
  display *cub->ray
end

### Go GDB Go! I Choose YOU! 

# main
break main
run ./maps/subject.cub
fs cmd
rfr

# break ft_get_small_delta
# run ./maps/subject.cub
# fs cmd
# rfr

### Info Stats
info break
info watch
