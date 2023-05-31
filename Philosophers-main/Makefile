NAME = philosophers

SRCS =	src/main.c \
		src/parsing.c \
		src/other.c \
		src/thread.c \
		src/other2.c
		
		

OBJS =	${SRCS:.c=.o}

GCC = gcc -pthread -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME) 

all: $(NAME)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all