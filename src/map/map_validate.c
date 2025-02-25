/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:44 by mario             #+#    #+#             */
/*   Updated: 2025/02/25 23:14:05 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	check_rectangle(t_map *map)
{
	int	i;
	int	len;

	if (map->height < 3 || map->width < 3)
		return (0);
	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->map[i]);
		if (len != map->height)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	int	i;
	int	y;
    int j;

    j = 0;
	i = 0;
	y = 0;
	while (map->map[i][y])
	{
		if (map->map[i][y] != 1)
			return (0);
		y++;
	}
	y = 0;
	i = map->height - 1;
	while (map->map[i][y])
	{
		if (map->map[i][y] != 1)
			return (0);
		y++;
	}
    while (map->map[j][0])
    {
        if (map->map[j][0] != 1)
            return (0);
        j++;
    }
    j = map->we
}
