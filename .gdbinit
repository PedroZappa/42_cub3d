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
end

### 200_parser.c
define parse_map
  display cub
  display cub->map
  display *cub->map->paths@4
  display *cub->map->imgs@4
  display *cub->map->map@cub->map->height
  display cub->map->floor_color
  display cub->map->ceiling_color
  display cub->map->start_pos
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

define parse_header
  display line
  display map
  display map->paths
  display map->paths[dir]
  display dir
  display dir_str[dir]
end

define parsing_colors
  display line
  display map
  display map->floor_color
  display map->ceiling_color
end

define parsing_map
  display map->map[line_count-1]
  display map->map[line_count]
  display map->map[line_count+1]
  
end

### Go GDB Go! I Choose YOU! 

# main
break ft_parse_map
run ./maps/subject.cub
fs cmd
rfr

### Info Stats
info break
info watch