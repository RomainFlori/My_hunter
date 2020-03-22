NAME	= my_hunter

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
		  ./thegame.c \
		  ./gameover.c \
		  ./my_putstr.c \
		  ./nb_tochar.c \
		  ./my_putchar.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -l csfml-system -l csfml-audio -l csfml-graphics -l csfml-network -l csfml-window
	 $(RM) $(OBJS)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
