/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:04:50 by mario             #+#    #+#             */
/*   Updated: 2025/03/17 12:11:22 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	find_player_position(t_game *game)
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

void	count_collectibles(t_game *game)
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

static int	init_map(t_game *game, char *map_path)
{
	game->map = malloc(sizeof(t_map) * 1);
	if (!game->map)
		return (0);
	if (!map_load(game->map, map_path))
		return (0);
	if (validate_map(game->map) != MAP_OK)
		return (0);
	return (1);
}

static void	cleanup_error(t_game *game, int stage)
{
	if (stage >= 2)
		free(game->graphics);
	if (stage >= 1)
	{
		free_char_tab(game->map->map);
		free(game->map);
	}
	free(game);
}

t_game	*init_game(char *map_path)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (!init_map(game, map_path))
	{
		cleanup_error(game, 1);
		return (NULL);
	}
	game->graphics = (t_graphics *)malloc(sizeof(t_graphics));
	if (!game->graphics)
	{
		cleanup_error(game, 1);
		return (NULL);
	}
	init_graphics_struct(game->graphics);
	if (!graphics_init(game->graphics, game->map))
	{
		game->graphics = NULL;
		cleanup_error(game, 2);
		return (NULL);
	}
	init_game_state(game);
	return (game);
}
