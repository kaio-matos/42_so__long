LIBFT_DIR			= libft
OBJS_DIR			= objects
SRC_DIR				= src
MANDATORY_DIR		= mandatory
BONUS_DIR			= bonus

CC					= cc
CCF_STRICT			= -Wall -Wextra -Werror
CCF_DEBUG			= -Wall -Wextra -Werror -g
MLX_FLAGS			= -lmlx -lXext -lX11 -lm
LIBS				= $(LIBFT_DIR)/libft.a $(MLX_FLAGS)
NAME				= so_long
RM					= rm -rf

################################################################################
# MANDATORY
################################################################################

CCF_INCL_MANDATORY	= -I ./$(SRC_DIR)/$(MANDATORY_DIR)/includes -I $(LIBFT_DIR)
C_FILES_MANDATORY	= main.c\
						app/so_long.c\
						mapper/map.c mapper/m__utils.c mapper/m__is_component.c mapper/m__checkers.c mapper/m__check_path.c mapper/m__getters.c mapper/m__setters.c\
						window/window.c window/w__render.c window/w__utils.c\
						memory/memory.c memory/memory_utils.c\
						state/game.c\
						utils/ft_free_matrix.c utils/ft_psplit.c utils/ft_read_file.c utils/ft_mtxiteri.c utils/ft_mtxsdup.c utils/ft_exit.c utils/ft_position.c\
						events/e__key_press.c events/move_player.c\
						logger/log.c
FILES_MANDATORY		= $(addprefix $(MANDATORY_DIR)/,$(C_FILES_MANDATORY))
SRCS_MANDATORY		= $(addprefix src/,$(FILES_MANDATORY))
OBJS_MANDATORY		= $(addprefix $(OBJS_DIR)/,$(FILES_MANDATORY:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_MANDATORY) libft
	$(CC) $(OBJS_MANDATORY) $(LIBS) -o $(NAME)

$(OBJS_DIR)/$(MANDATORY_DIR)/%.o: $(SRC_DIR)/$(MANDATORY_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CCF_STRICT) $(CCF_INCL_MANDATORY) -c $< -o $@

################################################################################
# BONUS
################################################################################

CCF_INCL_BONUS		= -I ./$(SRC_DIR)/$(BONUS_DIR)/includes -I $(LIBFT_DIR)
C_FILES_BONUS		= main_bonus.c\
						app/so_long_bonus.c\
						mapper/map_bonus.c mapper/m__utils_bonus.c mapper/m__is_component_bonus.c mapper/m__checkers_bonus.c mapper/m__check_path_bonus.c mapper/m__getters_bonus.c mapper/m__setters_bonus.c\
						window/window_bonus.c window/w__render_bonus.c window/w__utils_bonus.c\
						memory/memory_bonus.c memory/memory_utils_bonus.c\
						state/game_bonus.c\
						utils/ft_free_matrix_bonus.c utils/ft_psplit_bonus.c utils/ft_read_file_bonus.c utils/ft_mtxiteri_bonus.c utils/ft_mtxsdup_bonus.c utils/ft_exit_bonus.c utils/ft_position_bonus.c\
						events/e__key_press_bonus.c events/move_player_bonus.c\
						logger/log_bonus.c

FILES_BONUS			= $(addprefix $(BONUS_DIR)/,$(C_FILES_BONUS))
SRCS_BONUS			= $(addprefix src/,$(FILES_BONUS))
OBJS_BONUS			= $(addprefix $(OBJS_DIR)/,$(FILES_BONUS:.c=.o))

bonus: $(OBJS_BONUS) libft
	$(CC) $(OBJS_BONUS) $(LIBS) -o $(NAME)

$(OBJS_DIR)/$(BONUS_DIR)/%.o : $(SRC_DIR)/$(BONUS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CCF_STRICT) $(CCF_INCL_BONUS) -c $< -o $@

################################################################################
# LIBFT
################################################################################

libft:
	make all -C $(LIBFT_DIR)

################################################################################
# CLEAN UP
################################################################################

clean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean libft fclean re

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m