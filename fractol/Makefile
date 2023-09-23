NAME    = fractol

SRCS    = $(shell find "." -maxdepth 1 -name "*.c")

OBJS    = $(SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

CC      = gcc -ggdb

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
