/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:03:28 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 17:33:47 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	handle_close(void *param)
{
	exit_game((t_game *)param);
	return (0);
}
// Hook pour les touches du clavier

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->graphics->window, 2, 1L << 0, key_handler, game);
	mlx_hook(game->graphics->window, 17, 0, handle_close, game);
}

int	main(int ac, char **av)
{
	t_game	*game;
	//t_map	map;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long [map_file.ber]\n", 2);
		return (1);
	}
	game = init_game(av[1]);
	if (!game)
		return (1);
	setup_hooks(game);
	render_map(game->graphics, game->map);
	write (1, "Moves : 0\n", 10);
	mlx_loop(game->graphics->mlx);
	return (0);
}
