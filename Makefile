NAME = so_long
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror

SRCS =  ./src/main.c \
        ./src/game/game_init.c \
        ./src/graphics/graphics_init.c \
        ./src/graphics/graphics_utils.c \
        ./src/map/map_load.c \
        ./src/map/map_validate.c \
        ./src/map/map_render.c \
        ./src/map/map_validate_utils.c \
        ./src/map/map_path.c \
        ./src/player/player_move.c \
        ./src/utils/memory_management.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = lib/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
