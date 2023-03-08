HEAD = includes

SRCS = srcs/ft_printf.c srcs/hex_out.c srcs/cspdiuxX.c srcs/ft_utoa.c srcs/point_hex.c srcs/error_check.c\

LIBFT_DIR = libft

LIBFT = libft.a

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

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
	@make -C ${LIBFT_DIR}
	@cp ${LIBFT_DIR}/${LIBFT} .
	@mv ${LIBFT} ${NAME}
	@ar -rc ${NAME} $^
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean :
	@make clean -C ${LIBFT_DIR}
	@rm -f ${OBJS}
	@echo "$(BLUE)ft_printf, libft object files cleaned!$(DEF_COLOR)"

fclean : clean
	@rm -f ${LIBFT_DIR}/${LIBFT}
	@rm -f ${NAME}
	@echo "$(YELLOW)ft_printf, libft library files cleaned!$(DEF_COLOR)"

re :
	${MAKE} fclean
	${MAKE} all
	@echo "$(MAGENTA)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY : all clean fclean re
