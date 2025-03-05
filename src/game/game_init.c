/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:04:50 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 14:34:03 by mdodevsk         ###   ########.fr       */
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

	printf("Starting game initialization...\n");
	// Allocation de la structure principale
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	printf("Allocating map structure...\n");
	// Allocation de la structure de carte
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	printf("Loading map from %s...\n", map_path);
	// Chargement de la carte
	if (!map_load(game->map, map_path))
	{
		printf("Map loading failed!\n");
		free(game->map);
		free(game);
		return (NULL);
	}
	printf("Validating map...\n");
	// Validation de la carte
	if (validate_map(game->map) != MAP_OK)
	{
		printf("Map validation failed!\n");
		free_char_tab(game->map->map);
		free(game->map);
		free(game);
		return (NULL);
	}
	printf("Initializing graphics...\n");
	// Initialisation des graphismes
	game->graphics = (t_graphics *)malloc(sizeof(t_graphics));
	if (!game->graphics)
	{
		printf("Graphics allocation failed!\n");
		free_char_tab(game->map->map);
		free(game->map);
		free(game);
		return (NULL);
	}
	init_graphics_struct(game->graphics);
	printf("Starting MLX initialization...\n");
	if (!graphics_init(game->graphics, game->map))
	{
		printf("Graphics initialization failed!\n");
		free_char_tab(game->map->map);
		free(game->map);
		free(game->graphics);
		free(game);
		return (NULL);
	}
	printf("Setting initial game state...\n");
	// Configuration de l'état initial du jeu
	game->player.moves = 0;
	game->is_exit_reached = 0;
	find_player_position(game);
	count_collectibles(game);
	printf("Game initialization complete!\n");
	return (game);
}
