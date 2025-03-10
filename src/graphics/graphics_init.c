/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:09:59 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 13:44:45 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	load_single_texture(void *mlx, void **texture, char *path)
{
	int	width;
	int	height;

	*texture = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!*texture)
	{
		ft_putstr_fd("Error: Failed to load texture\n", 2);
		return (0);
	}
	return (1);
}

int	init_mlx(t_graphics *graphics)
{
	if (!graphics)
		return (0);
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
		return (0);
	return (1);
}

int	create_window(t_graphics *graphics, t_map *map)
{
	int	window_width;
	int	window_height;

	if (!graphics || !map || !graphics->mlx)
		return (0);
	window_width = map->width * SPRITE_SIZE;
	window_height = map->height * SPRITE_SIZE;
	graphics->window = mlx_new_window(graphics->mlx, window_width,
			window_height, "so_long");
	if (!graphics->window)
		return (0);
	graphics->height = window_height;
	graphics->width = window_width;
	return (1);
}

int	load_textures(t_graphics *graphics)
{
	if (!graphics || !graphics->mlx)
		return (0);
	if (!load_single_texture(graphics->mlx, &graphics->textures.player,
			PLAYER_XPM))
		return (0);
	if (!load_single_texture(graphics->mlx, &graphics->textures.wall, WALL_XPM))
		return (0);
	if (!load_single_texture(graphics->mlx, &graphics->textures.exit, EXIT_XPM))
		return (0);
	if (!load_single_texture(graphics->mlx, &graphics->textures.floor,
			FLOOR_XPM))
		return (0);
	if (!load_single_texture(graphics->mlx, &graphics->textures.collect,
			COLLECT_XPM))
		return (0);
	return (1);
}

int	graphics_init(t_graphics *graphics, t_map *map)
{
	if (!graphics || !map)
		return (-1);
	if (!init_mlx(graphics))
	{
		graphics_destroy(graphics);
		return (0);
	}
	if (!create_window(graphics, map))
	{
		graphics_destroy(graphics);
		return (0);
	}
	if (!load_textures(graphics))
	{
		graphics_destroy(graphics);
		return (0);
	}
	return (1);
}
