NAME		= libftprintf.a

SRCS		= convert_to_char.c convert_to_hex.c convert_to_integer.c\
			  convert_to_percent.c convert_to_string.c convert_to_pointer.c\
			  convert_to_unsigned_int.c ft_printf.c ft_putchar_fd.c\
			  ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c\

#BONUS_SRCS	= $(shell find "." -maxdepth 1 -name "*.c")

OBJS		= $(SRCS:.c=.o)

#BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror 

AR			= ar rcs

RM			= rm -f

CC			= cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

#bonus:	${BONUS_OBJS}
#	$(AR) $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re #bonus
