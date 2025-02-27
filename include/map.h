#ifndef MAP_H
# define MAP_H

/* Map Error Codes */
# define MAP_OK             0
# define ERR_NO_PLAYER      1
# define ERR_MULTI_PLAYER   2
# define ERR_NO_EXIT        3
# define ERR_MULTI_EXIT     4
# define ERR_NO_COLLECT     5
# define ERR_INVALID_CHAR   6
# define ERR_NOT_RECTANGLE  7
# define ERR_NO_WALLS       8
# define ERR_MAP_TOO_SMALL  9
# define ERR_NO_PATH        10
# define ERR_NO_PATH_COLL   11  

typedef struct s_map
{
    int     width;
    int     height;
    char    **map;
}   t_map;

typedef struct s_pos
{
    int     x;
    int     y;
}   t_pos;

int	map_load(t_map *map, char *map_path);
void    print_char_tab(char **tab);
void	print_map_error(int error_code);
int	is_valid_char(char c);
int	validate_count(int p, int e, int c);
void	count_elements(t_map *map, int *p, int *e, int *c);
int	check_elements(t_map *map);
size_t	get_line_width(char *line);
int		validate_map(t_map *map);

#endif
