SRCS = ft_printf.c utils.c

OBJECTS = ${SRCS:.c=.o}

BONUS =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS = ${BONUS:.c=.o}

NAME = libftprintf.a

.c.o :
	gcc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

libftprintf.a : ${OBJECTS}
	ar rc ${NAME} $^

all: libftprintf.a

clean :
	rm -f ${OBJECTS} ${BONUS_OBJS}

fclean :
	rm -f libftprintf.a

re : fclean all

bonus: ${OBJECTS} ${BONUS_OBJS}
	ar rc ${NAME} ${OBJECTS} ${BONUS_OBJS}