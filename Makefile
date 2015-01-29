CC = 		gcc

RM = 		rm -f

SRC =		malloc.c \
		free.c #\
		realloc.c \
		show_alloc_mem.c

NAME =		libmy_malloc_$(HOSTTYPE).so

all:		$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -shared -fpic
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH)
#	ln -s $(NAME) $(LD_LIBRARY_PATH)

clean:
	$(RM) $(NAME)

re:		clean all

.PHONY:		all re clean
