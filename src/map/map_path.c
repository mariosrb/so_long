/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:22:56 by mario             #+#    #+#             */
/*   Updated: 2025/02/27 18:06:04 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**copy_map(t_map *map)
{
    char    **copy;
    int     i;
    
    copy = malloc(sizeof (char *) * map->height + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < map->height)
    {
        copy = ft_strdup(map->map[i]);
        if (!copy)
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] == NULL;
    return (copy);
}

static void flood_fill(char **map, int x, int y, t_map *orig)
{
    if (x < 0 || y < 0 || x < orig->height || y < orig->width)
        return ;
    if (map[x][y] == 'F' || map[x][y] == '1')
        return ;
    map[x][y] = 'F';
    flood_fill(map, x + 1, y, orig);
    flood_fill(map, x - 1, y, orig);
    flood_fill(map, x, y + 1, orig);
    flood_fill(map, x, y - 1, orig);
}

int check_path(t_map *map)
{
    char    **map_copy;
    t_pos   player;
    int     result;
    
}