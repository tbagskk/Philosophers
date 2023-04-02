NAME = philosophers

SRCS =	src/main.c \
		src/parsing.c \
		src/other.c
		
		

OBJS =	${SRCS:.c=.o}

GCC = gcc -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME) 

all: $(NAME)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all