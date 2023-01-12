HEAD = get_next_line_bonus.h

SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line_bonus.a

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

${NAME} : ${OBJS}
	ar -rc ${NAME} $^

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re :
	${MAKE} fclean
	${MAKE} all

.PHONY : all clean fclean re
