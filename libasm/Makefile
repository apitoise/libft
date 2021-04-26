DIR_S = srcs

DIR_O = objs

SOURCES = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.s=.o))

NAME = libasm.a

CC = clang

CFLAGS = -Wall -Wextra

NASM = nasm

NASMFLAGS = -f elf64

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.s
	mkdir -p objs
	${NASM} ${NASMFLAGS} -o $@ $<

test: 
	$(CC) $(CFLAGS) main2.c $(NAME)

clean:
	rm -rf $(DIR_O)

fclean : clean
	rm -f $(NAME) rm a.out

re: fclean all

.PHONY: clean all fclean re
