/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:08:50 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 11:36:33 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (game->map->map[new_y][new_x] == '1')
		return ;
	if (game->map->map[new_y][new_x] == 'C')
	{
		game->collectibles_count--;
		game->map->map[new_y][new_x] = '0';
	}
	if (game->map->map[new_y][new_x] == 'E')
	{
		if (game->collectibles_count == 0)
			exit_game(game);
		return ;
	}
	game->map->map[game->player.y][game->player.x] = '0';
	game->player.x = new_x;
	game->player.y = new_y;
	game->map->map[new_y][new_x] = 'P';
	game->player.moves++;
	printf("Moves : %d\n", game->player.moves);
	render_map(game->graphics, game->map);
}
