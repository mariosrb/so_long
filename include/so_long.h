#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include "../lib/libft/libft.h"
# include "game.h"
# include "map.h"
# include "player.h"
# include "graphics.h"
# include "utils.h"

// Map
int	map_load(t_map *map, char *map_path);

// Memory management
void	free_char_tab(char **tab);

#endif
