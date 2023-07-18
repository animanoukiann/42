NAME    = push_swap

NAME2	= checker

SRCS    = $(shell find "." -maxdepth 1 -name "*.c" ! -name "checker*.c")

BONUS_SRCS	= $(shell find "." -maxdepth 1 -name "*.c" ! -name "push_swap.c")

OBJS    = $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

CC      = cc

all: $(NAME) $(NAME1)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME2)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all bonus clean fclean re

test:	$(NAME)
		$(eval ARG = $(shell jot -r 100 0 20000000))
		./push_swap $(ARG) | ./checker_Mac $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l
