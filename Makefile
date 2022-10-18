LIBFT_DIR		= libft
OBJS_DIR		= objects

CC				= cc
CCF_INCLUDES	= -I ./includes -I $(LIBFT_DIR)
CCF_STRICT		= -Wall -Wextra -Werror
CCF_DEBUG		= -Wall -Wextra -Werror -g
MLX_FLAGS		= -lmlx -lXext -lX11 -lm
LIBS			= $(LIBFT_DIR)/libft.a $(MLX_FLAGS)
NAME			= so_long
FILES			= main.c\
					app/so_long.c\
					mapper/map.c mapper/m__utils.c mapper/m__is_component.c mapper/m__checkers.c mapper/m__check_path.c mapper/m__getters.c mapper/m__setters.c\
					window/window.c window/w__render.c window/w__utils.c\
					memory/memory.c memory/memory_utils.c\
					state/game.c\
					utils/ft_free_matrix.c utils/ft_psplit.c utils/ft_read_file.c utils/ft_mtxiteri.c utils/ft_mtxsdup.c utils/ft_exit.c utils/ft_position.c\
					events/e__key_press.c events/move_player.c\
					logger/log.c
SRCS			= $(addprefix src/,$(FILES))
OBJS			= $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
RM				= rm -rf

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS_DIR)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(CCF_STRICT) $(CCF_INCLUDES) -c $< -o $@

libft:
	make all -C $(LIBFT_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all debug clean libft fclean re

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