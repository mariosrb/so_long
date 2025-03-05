#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	t_player	player;
	int			collectibles_count;
	int			collectibles_total;
	int			is_exit_reached;
	t_map		*map;
	t_graphics	*graphics;
}				t_game;

t_game			*init_game(char *map_path);

#endif
