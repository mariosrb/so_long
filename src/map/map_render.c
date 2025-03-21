/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:59 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 11:35:57 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	render_tile(t_graphics *graphics, int row, int col, char tile_type)
{
	int		x;
	int		y;
	void	*img;

	x = col * SPRITE_SIZE;
	y = row * SPRITE_SIZE;
	mlx_put_image_to_window(graphics->mlx, graphics->window,
		graphics->textures.floor, x, y);
	if (tile_type == '1')
		img = graphics->textures.wall;
	else if (tile_type == 'C')
		img = graphics->textures.collect;
	else if (tile_type == 'E')
		img = graphics->textures.exit;
	else if (tile_type == 'P')
		img = graphics->textures.player;
	else
		return ;
	mlx_put_image_to_window(graphics->mlx, graphics->window, img, x, y);
}

int	render_map(t_graphics *graphics, t_map *map)
{
	int	row;
	int	col;

	if (!graphics || !map || !map->map)
		return (0);
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			render_tile(graphics, row, col, map->map[row][col]);
			col++;
		}
		row++;
	}
	return (1);
}
