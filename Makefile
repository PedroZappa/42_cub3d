# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 20:35:29 by passunca          #+#    #+#              #
#    Updated: 2024/09/25 16:30:16 by gfragoso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

SHELL	:= bash --rcfile ~/.bashrc
MAKE	= make -C

# Default test values
IN_PATH		?= $(SRC_PATH)
ARG			= "./maps/subject.cub"
# ARG			= "./maps/map-path-rgb.cub"
# ARG			= "./maps/map-rgb-path.cub"
# ARG			= "./maps/path-map-rgb.cub"
# ARG			= "./maps/rgb-map-path.cub"
# ARG			= "./maps/rgb-path-map.cub"

COUNTER		:= 1

#==============================================================================#
#                                RESOURCES URLS                                #
#==============================================================================#

LIBFT_URL 	= git@github.com:PedroZappa/42_libft.git
MLX_URL 	= https://cdn.intra.42.fr/document/document/25858/minilibx-linux.tgz

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

NAME 			= cub3D

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH		= src
INC_PATH		= inc
LIBS_PATH		= lib
MAPS_PATH		= maps
BUILD_PATH		= .build
TEMP_PATH		= .temp

SRC				= $(wildcard $(SRC_PATH)/*.c)
OBJS			= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

HEADERS			= $(wildcard $(INC_PATH)/*.h)

LIBFT_PATH		= $(LIBS_PATH)/libft
LIBFT_ARC		= $(LIBFT_PATH)/libft.a

MLX_PATH		= $(LIBS_PATH)/mlx
MLX_ARC			= $(MLX_PATH)/libmlx_Linux.a

INVALID_MAPS	= $(shell ls -al $(MAPS_PATH)/invalid/*.cub | awk '{print $$9}')

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC			= cc

CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -ggdb3
#DFLAGS		+= -fno-limit-debug-info

RFLAGS		= -lm -lX11 -lXext
INC			= -I $(INC_PATH)

BUILD 		?= all
ASAN_FLAGS	= -fsanitize=address

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

### Core Utils
RM		= rm -rf
AR		= ar rcs
MKDIR_P	= mkdir -p

### Valgrind
VAL_SUP 	= --suppressions=mlx.sup
VAL_LEAK	= --leak-check=full --show-leak-kinds=all --trace-children=yes
VAL_FD		= --track-fds=yes --track-origins=yes
VGDB_ARGS	= --vgdb-error=0 $(VAL_LEAK) $(VAL_SUP) $(VAL_FD)

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ minishell Compilation Rules 🏗

all: deps $(BUILD_PATH) $(NAME)	## Compile

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(MLX_ARC) $(OBJS)			## Compile
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) mandatory version$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(INC) $(LIBFT_ARC) $(MLX_ARC) $(RFLAGS) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"
	make norm

cub: all
	@./$(NAME) $(ARG)

asan: CFLAGS += $(ASAN_FLAGS)
asan: $(BUILD_PATH) $(LIBFT_ARC) $(MLX_ARC) $(OBJS)   ## Compile with Address Sanitizer
	@echo "$(YEL)Compiling $(MAG)$(NAME)$(YEL) with Address Sanitizer$(D)"
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT_ARC) $(MLX_ARC) $(RFLAGS) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) with Address Sanitizer $(YEL)🖔$(D)]"

deps:		## Download/Update deps
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found 🖔"; fi
	@if test ! -d "$(MLX_PATH)"; then make get_mlx; \
		else echo "$(YEL)[mlx]$(D) folder found 🖔"; fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"

skip_verify: DFLAGS += -D SKIP_VERIFY=1
skip_verify: re

-include $(BUILD_PATH)/%.d

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) -MMD -MP -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(CYA)$(TEMP_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra

get_libft:
	@echo "* $(CYA)Getting Libft submodule$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	@if test ! -d "$(LIBFT_PATH)"; then \
		git clone $(LIBFT_URL) $(LIBFT_PATH); \
		echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)Libft submodule already exists 🖔"; \
	echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; \
	fi

$(MLX_ARC):
	$(MAKE) $(MLX_PATH)

get_mlx:
	@echo "* $(CYA)Getting MLX submodule$(D)"
	@$(MKDIR_P) $(LIBS_PATH)
	@if test ! -d "$(MLX_PATH)"; then \
		curl -kL $(MLX_URL) | tar zxvf -; \
		mv minilibx-linux ./lib/mlx; \
		echo "* $(GRN)MLX submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)MLX submodule already exists 🖔"; \
	echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; \
	fi

##@ Norm Rules

norm:
	@make --no-print-directory norm_path IN_PATH=$(SRC_PATH)
	@make --no-print-directory norm_path IN_PATH=$(INC_PATH)

norm_path: $(TEMP_PATH)		## Run norminette test on source files
	@echo "$(CYA)$(_SEP)$(D)"
	@printf "${_NORM}: $(YEL)$(IN_PATH)$(D)\n"
	@ls $(IN_PATH) | wc -l > $(TEMP_PATH)/norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(IN_PATH) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(IN_PATH) | grep -v "OK" > $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi
	@echo "$(CYA)$(_SEP)$(D)"

check_ext_func: all		## Check for external functions
	@echo "[$(YEL)Checking for external functions$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)Reading binary$(D): $(MAG)$(NAME)$(D)"
	nm ./$(NAME) | grep "U" | grep -v "__" | tee $(TEMP_PATH)/ext_func.txt
	@echo "$(YEL)$(_SEP)$(D)"

##@ Test Rules 🧪

test_err: all		## Test invalid map input
	@TIMESTAMP=$(shell date +%Y%m%d%H%M%S); \
	if [ -f $(TEMP_PATH)/out.txt ]; then \
		mv -f $(TEMP_PATH)/out.txt $(TEMP_PATH)/out.$$TIMESTAMP.txt; \
	fi
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "[$(RED)Testing invalid input$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "Test $(MAG)1$(D) : $(CYA)Running $(D): $(MAG)$(NAME)$(D) w/out input map" | tee -a $(TEMP_PATH)/out.txt 
	-valgrind $(VAL_LEAK) $(VAL_SUP) --log-file=$(TEMP_PATH)/temp.txt ./$(NAME)
	@sed -n '10p' $(TEMP_PATH)/temp.txt >> $(TEMP_PATH)/out.txt
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "Test $(MAG)2$(D) : $(CYA)Running $(D): $(MAG)$(NAME)$(D) w/ unexistent input map" | tee -a $(TEMP_PATH)/out.txt
	-valgrind $(VAL_LEAK) $(VAL_SUP) --log-file=$(TEMP_PATH)/temp.txt ./$(NAME) $(MAPS_PATH)/unexistent_map.cub
	@sed -n '10p' $(TEMP_PATH)/temp.txt >> $(TEMP_PATH)/out.txt
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)Running $(D): $(MAG)$(NAME)$(D) w/ invalid input maps"
	@COUNTER=$$((COUNTER + 3)); \
	for map in $(INVALID_MAPS); do \
		echo "Test $(MAG)$$COUNTER$(D) : Executing $(CYA)$$map$(D)" | tee -a $(TEMP_PATH)/out.txt; \
		VALGRIND_CMD="valgrind $(VAL_LEAK) $(VAL_SUP) --log-file=$(TEMP_PATH)/temp.txt ./$(NAME) '$$map'"; \
		echo "$$VALGRIND_CMD" | tee -a $(TEMP_PATH)/out.txt; \
		eval $$VALGRIND_CMD; \
		sed -n '10p' $(TEMP_PATH)/temp.txt >> $(TEMP_PATH)/out.txt; \
		COUNTER=$$((COUNTER + 1)); \
		echo $$COUNTER > $(TEMP_PATH)/passed_count.txt; \
		echo "$(YEL)$(_SEP)$(D)"; \
	done
	@echo "[$(GRN)Finished$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"

##@ Debug Rules 

gdb: all $(NAME) $(TEMP_PATH)			## Debug w/ gdb
	tmux split-window -h "gdb --tui ./$(NAME)"
	# tmux resize-pane -L 5
	# tmux split-window -v "btop"
	make get_log

vgdb: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck) & gdb
	tmux split-window -h "valgrind $(VGDB_ARGS) --log-file=gdb.txt ./$(NAME) $(ARG)"
	make vgdb_cmd
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	# tmux resize-pane -U 18
	# tmux split-window -v "btop"
	make get_log

valgrind: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck)
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind $(VAL_ARGS) $(VAL_LEAK) $(VAL_FD) ./$(NAME) $(ARG)"

massif: all $(TEMP_PATH)		## Run Valgrind w/ Massif (gather profiling information)
	@TIMESTAMP=$(shell date +%Y%m%d%H%M%S); \
	if [ -f massif.out.* ]; then \
		mv -f massif.out.* $(TEMP_PATH)/massif.out.$$TIMESTAMP; \
	fi
	@echo " 🔎 [$(YEL)Massif Profiling$(D)]"
	valgrind --tool=massif --time-unit=B ./$(NAME) $(ARG)
	ms_print massif.out.*
# Learn more about massif and ms_print:
### https://valgrind.org/docs/manual/ms-manual.html

get_log:
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

vgdb_cmd: $(NAME) $(TEMP_PATH)
	@printf "target remote | vgdb --pid=" > $(TEMP_PATH)/gdb_commands.txt
	@printf "$(shell pgrep -f valgrind)" >> $(TEMP_PATH)/gdb_commands.txt
	@printf "\n" >> $(TEMP_PATH)/gdb_commands.txt
	@cat .vgdbinit >> $(TEMP_PATH)/gdb_commands.txt

##@ Clean-up Rules 󰃢

clean:				## Remove object files
	@echo "*** $(YEL)Removing $(MAG)$(NAME)$(D) and deps $(YEL)object files$(D)"
	@if [ -d "$(BUILD_PATH)" ] || [ -d "$(TEMP_PATH)" ]; then \
		if [ -d "$(BUILD_PATH)" ]; then \
			$(RM) $(BUILD_PATH); \
			echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(TEMP_PATH)" ]; then \
			$(RM) $(TEMP_PATH); \
			echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to clean!$(D)]"; \
	fi

fclean: clean			## Remove executable and .gdbinit
	@if [ -f "$(NAME)" ]; then \
		if [ -f "$(NAME)" ]; then \
			$(RM) $(NAME); \
			$(RM) compile_commands.json; \
			echo "* $(YEL)Removing $(CYA)$(NAME)$(D) file: $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to be fcleaned!$(D)]"; \
	fi

libclean: fclean	## Remove libs
	$(RM) $(LIBS_PATH)
	$(RM) compile_commands.json
	@echo "* $(YEL)Removing lib folder & files!$(D) : $(_SUCCESS)"

re: fclean all	## Purge & Recompile

##@ Help 󰛵

help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-18s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: bonus clean fclean re help

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)

