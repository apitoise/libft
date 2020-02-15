DIR_S = srcs

DIR_O = objs

MLX_DIR = minilibx

LIBFT_DIR = Libft

HEADER = header

NAME = Cube3D

SOURCES = check_arguments.c \
			check_map.c \
			draw.c \
			draw_sprites.c \
			ft_error.c \
			ft_move.c \
			ft_raycasting.c \
			get_map.c \
			get_next_line.c \
			get_texnsprite.c \
			gnl_utils.c \
			init_colors.c \
			init_loop_algostruct.c \
			init_mapstruct.c \
			init_params.c \
			init_struct.c \
			keyparsing.c \
			main.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -framework OpenGL -framework AppKit

MLX_LIB = $(addprefix $(MLX_DIR)/,libmlx.a)

LIBFT = $(addprefix $(LIBFT_DIR)/,libft.a)

all: $(LIBFT) $(MLX) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all fclean re