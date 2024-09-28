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
  display cub->current_pos
  display cub->start_pos->x
  display cub->start_pos->y
  display file
  display fd
end

define parse_loop
  display map
  display line
  display parsing_map
end

define parse_header
  display line
  display map
  display map->paths
  display map->paths[dir]
  display dir
  display dir_str[dir]
end

define parse_map

end

### Go GDB Go! I Choose YOU! 

# main
break ft_export
run
fs cmd
rfr

### Info Stats
info break
info watch
