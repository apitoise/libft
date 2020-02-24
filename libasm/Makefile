DIR_S = srcs

DIR_O = objs

SOURCES = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.s=.o))

NAME = libasm.a

CC = nasm

CFLAGS = -f macho64

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs	$(NAME)	$(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.s
	mkdir -p objs
	${CC} ${CFLAGS} -o $@ $<

clean:
	rm -rf $(DIR_O)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
