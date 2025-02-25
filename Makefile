NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ./src/main.c \
        ./src/game/game_init.c \
        ./src/game/game_loop.c \
        ./src/game/game_utils.c \
        ./src/graphics/graphics_init.c \
        ./src/graphics/graphics_utils.c \
        ./src/graphics/graphics_render.c \
        ./src/map/map_load.c \
        ./src/map/map_validate.c \
        ./src/map/map_render.c \
        ./src/player/player_collect.c \
        ./src/player/player_move.c \
        ./src/utils/error_handling.c \
        ./src/utils/memory_management.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
