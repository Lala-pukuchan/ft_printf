CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_utoa.c \
	ft_printf.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFTDIR = libft/
LIBFTNAME = libft.a
all: $(NAME)

$(NAME): $(OBJS)
	cd $(LIBFTDIR) && make
	cp -p $(LIBFTDIR)$(LIBFTNAME) $(NAME)
	ar r $(NAME) $(OBJS)

clean:
	cd $(LIBFTDIR) && make clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
