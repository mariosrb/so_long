/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:11:02 by mario             #+#    #+#             */
/*   Updated: 2025/03/03 12:03:16 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
void    exit_game(t_game *game)
{
    if (game->map && game->map->map)
        free_char_tab(game->map->map);
    graphics_destroy(game->graphics);
    free(game);
    exit(0);
}
