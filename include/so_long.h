#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"

# include "player.h"
# include "map.h"
# include "graphics.h"
# include "game.h"
# include "utils.h"

// Map
int	map_load(t_map *map, char *map_path);

#endif
