NAME    = push_swap
 
PRINTF =  libftprintf.a

HEADER  = push_swap.h

SRCS    = $(shell find "." -maxdepth 1 -name "*.c")

OBJS    = $(SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror 
-g3 -fsanitize=address

RM      = rm -f

CC      = cc

all: $(NAME)

$(NAME): $(OBJS)
	make -C printf
	$(CC) $(CFLAGS) $(OBJS) printf/$(PRINTF) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

test:	$(NAME)
		$(eval ARG = $(shell jot -r 500 0 20000000))
		./push_swap $(ARG) | ./checker_Mac $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l
