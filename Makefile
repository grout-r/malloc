CC = 		gcc

RM = 		rm -f

SRC =		malloc.c \
		free.c \
		misc.c \
		show_alloc_mem.c \
		realloc.c \
		calloc.c

NAME =		libmy_malloc_$(HOSTTYPE).so

all:		$(NAME)

$(NAME):
	$(CC) -shared -fpic -Wall -Wextra -Werror $(SRC) -o $(NAME)
#	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH)
#	ln -s $(NAME) $(LD_LIBRARY_PATH)

clean:
	$(RM) $(NAME)

re:		clean all

.PHONY:		all re clean
