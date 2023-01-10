HEAD = includes

SRCS = srcs/ft_printf.c srcs/hex_out.c srcs/cspdiuxX.c srcs/ft_utoa.c srcs/point_hex.c\
	   libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c\
	   libft/ft_strdup.c libft/ft_strlen.c\

LIBFT = libft/libft.a

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

${NAME} : ${OBJS}
	ar -rc ${NAME} $^ ${LIBFT}

test : 
	${CC} ${CFLAGS} ${LIBFT} ${NAME} test.c -I ${HEAD}

debug :
	${CC} -g3 ${LIBFT} ${NAME} test.c -I ${HEAD}

san :
	${CC} -g3 -fsanitize=address ${LIBFT} ${NAME} test.c -I ${HEAD}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re :
	${MAKE} fclean
	${MAKE} all

.PHONY : all clean fclean re
