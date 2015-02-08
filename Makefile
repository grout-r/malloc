CC = 		gcc

RM = 		rm -f

CFLAGS =	-fpic -Wall -Wextra -Werror #-pedantic

SRC =		malloc.c \
		free.c \
		misc.c \
		show_alloc_mem.c \
		realloc.c \
		calloc.c

OBJ =		$(SRC:.c=.o)

NAME1 =		libmy_malloc_$(HOSTTYPE).so

NAME2 =		libmy_malloc.so

all:		$(NAME1)

$(NAME1):	$(OBJ)
	$(CC) $(OBJ) -shared -o $(NAME1)
	ln -fs $(NAME1) $(NAME2)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re:		fclean all

.PHONY:		all re clean fclean
