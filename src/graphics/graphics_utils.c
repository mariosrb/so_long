/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:10:24 by mario             #+#    #+#             */
/*   Updated: 2025/03/01 17:46:10 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    init_graphics_struct(t_graphics *graphics)
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

void    graphics_destroy(t_graphics *graphics)
{
    if (!graphics)
        return ;
    if (graphics->mlx)
    {
        if (graphics->textures.player)
        {
            mlx_destroy_image(graphics->mlx, graphics->textures.player);
            graphics->textures.player = NULL;
        }
        if (graphics->textures.exit)
        {
            mlx_destroy_image(graphics->mlx, graphics->textures.exit);
            graphics->textures.exit = NULL;
        }
        if (graphics->textures.collect)
        {
            mlx_destroy_image(graphics->mlx, graphics->textures.collect);
            graphics->textures.collect = NULL;
        }
        if (graphics->textures.floor)
        {
            mlx_destroy_image(graphics->mlx, graphics->textures.floor);
            graphics->textures.floor = NULL;
        }
        if (graphics->textures.wall)
        {
            mlx_destroy_image(graphics->mlx, graphics->textures.wall);
            graphics->textures.wall = NULL;
        }
        if (graphics->window)
        {
            mlx_destroy_window(graphics->mlx, graphics->window);
            graphics->window = NULL;
        }
        mlx_destroy_display(graphics->mlx);
        free(graphics->mlx);
        graphics->mlx = NULL;
    }
    free(graphics);
}

