SRCS	= ft_printf.c ft_write.c ft_utils.c

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
