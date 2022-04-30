SOURCES = ft_printf.c ft_printf_funcs.c ft_types.c
OBJS = ${SOURCES:.c=.o}

NAME=libftprintf.a
INCLUDES = ft_printf.h
CC = clang
AR = ar
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

.c.o:
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all:${NAME}

${NAME}:${OBJS}
		@${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean:clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
