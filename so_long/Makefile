HEAD = includes

SRCS = srcs/get_next_line.c srcs/get_next_line_utils.c srcs/keyboard_input.c srcs/main.c\
	   srcs/map_init.c srcs/map_set.c srcs/so_long_util.c\


OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

#color
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all : ${NAME}

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

${NAME} : ${OBJS}
	@${CC} -L./mini_libx/minilibx-linux -lmlx -framework OpenGL -framework AppKit -o ${NAME} $^
	@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

clean :
	@rm -f ${OBJS}
	@echo "$(BLUE)so_long object files cleaned!$(DEF_COLOR)"

fclean : clean
	@rm -f ${NAME}
	@echo "$(YELLOW)so_long library files cleaned!$(DEF_COLOR)"

re :
	${MAKE} fclean
	${MAKE} all
	@echo "$(MAGENTA)Cleaned and rebuilt everything for so_long!$(DEF_COLOR)"

.PHONY : all clean fclean re