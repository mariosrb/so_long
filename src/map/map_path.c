/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:22:56 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 11:46:26 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy)
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_map *orig)
{
	if (x < 0 || y < 0 || x >= orig->width || y >= orig->height)
		return ;
	if (map[y][x] == 'F' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, orig);
	flood_fill(map, x - 1, y, orig);
	flood_fill(map, x, y + 1, orig);
	flood_fill(map, x, y - 1, orig);
}

static t_pos	find_player(t_map *map)
{
	t_pos	pos;
	int		i;
	int		j;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

static int	check_reachable(char **filled_map, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C' && filled_map[i][j] != 'F')
				return (print_map_error(ERR_NO_PATH), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_map *map)
{
	char	**map_copy;
	t_pos	player;
	int		result;

	map_copy = copy_map(map);
	if (!map_copy)
		return (print_map_error(ERR_MEMORY), 0);
	player = find_player(map);
	if (player.x == -1 || player.y == -1)
	{
		free_char_tab(map_copy);
		return (print_map_error(ERR_NO_PLAYER), 0);
	}
	flood_fill(map_copy, player.x, player.y, map);
	result = check_reachable(map_copy, map);
	free_char_tab(map_copy);
	return (result);
}
