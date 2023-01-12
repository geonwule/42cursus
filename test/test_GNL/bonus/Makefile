HEAD = get_next_line.h

HEAD_B = get_next_line_bonus.h

SRCS = get_next_line.c get_next_line_utils.c

SRCS_B = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

NAME_B = get_next_line_bonus.a

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

${NAME} : ${OBJS}
	ar -rc ${NAME} $^

bonus : ${OBJS_B}
	ar -rc ${NAME_B} $^

clean :
	rm -f ${OBJS} ${OBJS_B}

fclean : clean
	rm -f ${NAME} ${NAME_B}

re :
	${MAKE} fclean
	${MAKE} all

.PHONY : all clean fclean re bonus
