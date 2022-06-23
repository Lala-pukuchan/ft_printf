CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_utoa.c \
	ft_printf.c \
	ft_output_cs.c \
	ft_output_du.c \
	ft_output_px.c \
	ft_sort.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFTDIR = libft/
LIBFTNAME = libft.a

all: $(NAME)

# make -CでPWDを変更せずに、サブディレクトリのMakefileを実行できる。
# libft.aをlibftprintf.aにmvすることで、fcleanの際に、libft.aを削除する工程を省略。
# make -C $(LIBFTDIR)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	mv $(LIBFTDIR)$(LIBFTNAME) ./$(NAME)
	ar r $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# PHONYで同一ファイル名が存在してもコマンドが利用可能になる。
.PHONY: all fclean clean re
