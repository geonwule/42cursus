HEAD = ./includes

SRCS = srcs/main.c srcs/a_to_b.c srcs/b_to_a.c srcs/a_to_b_f_util.c srcs/a_to_b_util.c\
		srcs/check_error.c srcs/check_error2.c\
		srcs/free.c srcs/linked_list.c srcs/order1.c srcs/order2.c srcs/order3.c srcs/sort_util.c\

PRINTF_DIR = ft_printf

PRINTF = libftprintf.a

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

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
	@make -C ${PRINTF_DIR}
	@mv ${PRINTF_DIR}/${PRINTF} .
	@${CC} ${CFLAGS} $^ ${PRINTF} -o ${NAME} -I ${HEAD}
	@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"

debug : ${OBJS}
	@${CC} -g3 -fsanitize=address $^ ${PRINTF} -o ${NAME} -I ${HEAD}
	@echo "$(GREEN)push_swap debug file compiled!$(DEF_COLOR)"

clean :
	@make clean -C ${PRINTF_DIR}
	@rm -f ${OBJS}
	@echo "$(BLUE)push_swap, printf object files cleaned!$(DEF_COLOR)"

fclean : clean
	@make fclean -C ${PRINTF_DIR}
	@rm -f ${PRINTF}
	@rm -f ${NAME}
	@echo "$(YELLOW)push_swap, printf library files cleaned!$(DEF_COLOR)"

re :
	${MAKE} fclean
	${MAKE} all
	@echo "$(MAGENTA)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

.PHONY : all clean fclean re
