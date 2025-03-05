#ifndef GRAPHICS_H
# define GRAPHICS_H

# define SPRITE_SIZE 40
# define WALL_XPM "./asset/wall.xpm"
# define FLOOR_XPM "./asset/floor.xpm"
# define COLLECT_XPM "./asset/collect.xpm"
# define EXIT_XPM "./asset/exit.xpm"
# define PLAYER_XPM "./asset/player.xpm"

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*collect;
	void		*exit;
	void		*player;
	int			size;
}				t_textures;

typedef struct s_graphics
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	t_textures	textures;
}				t_graphics;

// Initialisation generale des graphismes
int				graphics_init(t_graphics *graphics, t_map *map);
void			init_graphics_struct(t_graphics *graphics);

// Initialisation de la Mlx
int				init_mlx(t_graphics *graphics);
int				create_window(t_graphics *graphics, t_map *map);

// Chargement des textures
int				load_textures(t_graphics *graphics);

// Nettoyage des ressources graphiques
void			graphics_destroy(t_graphics *graphics);

#endif
