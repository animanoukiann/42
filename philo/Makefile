NAME    = philo

SRCS    = $(shell find "." -maxdepth 1 -name "*.c")

OBJS    = $(SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror -g #-fsanitize=thread

RM      = rm -f

CC      = gcc -ggdb

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re