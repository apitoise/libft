DIR_S = srcs

DIR_O = objs

SOURCES = ft_digitflags.c \
			ft_parsing.c \
			ft_printf.c \
			init_struct.c \
			is_conv.c \
			pf_c.c \
			pf_cx.c \
			pf_id.c \
			pf_p.c \
			pf_percent.c \
			pf_s.c \
			pf_u.c \
			pf_x.c \
			search_flags.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEADERS = headers

LIBFT = Libft

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp Libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p objs
	${CC} ${CFLAGS} -I ${HEADERS} -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean all fclean re
