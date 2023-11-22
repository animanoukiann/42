NAME    = pipex

SRCS    = $(shell find "." -maxdepth 1 -name "*.c")

BONUS_SRCS	= $(shell find "." -maxdepth 1 -name "*.c")

OBJS    = $(SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

CC      = gcc -ggdb

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re