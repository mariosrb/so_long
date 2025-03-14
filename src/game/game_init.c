/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:04:50 by mario             #+#    #+#             */
/*   Updated: 2025/03/14 14:37:36 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	printf("Finding player position...\n");
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			printf("Checking position %d,%d: %c\n", i, j, game->map->map[i][j]);
			if (game->map->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				printf("Player found at %d,%d\n", i, j);
				return ;
			}
			j++;
		}
		i++;
	}
	printf("WARNING: Player not found in map!\n");
}

static void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	printf("Counting collectibles...\n");
	game->collectibles_count = 0;
	game->collectibles_total = 0;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'C')
				game->collectibles_total++;
			j++;
		}
		i++;
	}
	game->collectibles_count = game->collectibles_total;
	printf("Found %d collectibles\n", game->collectibles_total);
}

t_game	*init_game(char *map_path)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	if (!map_load(game->map, map_path))
	{
		free(game->map);
		free(game);
		return (NULL);
	}
	if (validate_map(game->map) != MAP_OK)
	{
		free_char_tab(game->map->map);
		free(game->map);
		free(game);
		return (NULL);
	}
	game->graphics = (t_graphics *)malloc(sizeof(t_graphics));
	if (!game->graphics)
	{
		free_char_tab(game->map->map);
		free(game->map);
		free(game);
		return (NULL);
	}
	init_graphics_struct(game->graphics);
	if (!graphics_init(game->graphics, game->map))
	{
		free_char_tab(game->map->map);
		free(game->map);
		free(game->graphics);
		free(game);
		return (NULL);
	}
	game->player.moves = 0;
	game->is_exit_reached = 0;
	find_player_position(game);
	count_collectibles(game);
	return (game);
}
