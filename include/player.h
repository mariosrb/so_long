#ifndef PLAYER_H
# define PLAYER_H

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_player
{
	int					x;
	int					y;
	int					moves;
}						t_player;

typedef struct s_game	t_game;

int						key_handler(int keycode, t_game *game);
void					move_player(t_game *game, int dx, int dy);

#endif
