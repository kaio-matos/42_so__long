CC = cc
CCF_INCLUDES = -I ./includes -I ./libft
CCF_STRICT = -Wall -Wextra -Werror
CCF_DEBUG = -Wall -Wextra -Werror -g
NAME = so_long
SRCS = main.c mapper/map.c mapper/map_utils.c mapper/is_component.c logger/log.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make all -C ./libft
	$(CC) $(OBJS) ./libft/libft.a $(CCF_INCLUDES) -o $(NAME)

%.o : %.c
	$(CC) $(CCF_STRICT) $(CCF_INCLUDES) -c $< -o $@

debug:
	make all -C ./libft
	$(CC) $(CCF_DEBUG) $(SRCS) ./libft/libft.a $(CCF_INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all debug clean fclean re

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