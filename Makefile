SRCS	= ft_printf.c \
	ft_check_np.c ft_check_pc.c ft_check_s.c ft_check_unhex.c \
	ft_put_pointer.c ft_putnbr_base.c ft_putstr.c ft_strlen.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

OBJCS	= $(SRCS:.c=.o)
HEADER	= ft_printf.h

NAME	= libftprintf.a

$(NAME): $(OBJCS) 
	@ar rcs $@ $^

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJCS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: clean
