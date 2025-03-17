/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:10:24 by mario             #+#    #+#             */
/*   Updated: 2025/03/17 11:37:23 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_graphics_struct(t_graphics *graphics)
{
	graphics->mlx = NULL;
	graphics->window = NULL;
	graphics->textures.player = NULL;
	graphics->textures.exit = NULL;
	graphics->textures.collect = NULL;
	graphics->textures.floor = NULL;
	graphics->textures.wall = NULL;
	graphics->width = 0;
	graphics->height = 0;
}

void	graphics_destroy(t_graphics *graphics)
{
	if (!graphics)
		return ;
	if (graphics->mlx)
	{
		if (graphics->textures.player)
			mlx_destroy_image(graphics->mlx, graphics->textures.player);
		if (graphics->textures.exit)
			mlx_destroy_image(graphics->mlx, graphics->textures.exit);
		if (graphics->textures.collect)
			mlx_destroy_image(graphics->mlx, graphics->textures.collect);
		if (graphics->textures.floor)
			mlx_destroy_image(graphics->mlx, graphics->textures.floor);
		if (graphics->textures.wall)
			mlx_destroy_image(graphics->mlx, graphics->textures.wall);
		if (graphics->window)
			mlx_destroy_window(graphics->mlx, graphics->window);
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
		graphics->mlx = NULL;
	}
	free(graphics);
}

void	init_game_state(t_game *game)
{
	game->player.moves = 0;
	game->is_exit_reached = 0;
	find_player_position(game);
	count_collectibles(game);
}
