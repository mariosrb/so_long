/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:44 by mario             #+#    #+#             */
/*   Updated: 2025/03/06 12:25:27 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	check_rectangle(t_map *map)
{
	int	i;
	int	len;

	if (map->height < 3 || map->width < 3)
		return (ERR_MAP_TOO_SMALL);
	i = 0;
	while (i < map->height)
	{
		len = get_line_width(map->map[i]);
		if (len != map->width)
			return (ERR_NOT_RECTANGLE);
		i++;
	}
	return (0);
}

static int	check_walls(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map)
		return (0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1) || (j == 0 || j == map->width
					- 1))
			{
				if (map->map[i][j] != '1')
					return (ERR_NO_WALLS);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_elements(t_map *map)
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!is_valid_char(map->map[i][j]))
				return (ERR_INVALID_CHAR);
			j++;
		}
		i++;
	}
	count_elements(map, &p_count, &e_count, &c_count);
	return (validate_count(p_count, e_count, c_count));
}

int	validate_map(t_map *map)
{
	int	error_code;

	error_code = check_rectangle(map);
	if (error_code != MAP_OK)
		return (print_map_error(error_code), error_code);
	error_code = check_walls(map);
	if (error_code != MAP_OK)
		return (print_map_error(error_code), error_code);
	error_code = check_elements(map);
	if (error_code != MAP_OK)
		return (print_map_error(error_code), error_code);
	error_code = check_path(map);
	if (error_code != MAP_OK)
		return (print_map_error(error_code), error_code);
	return (MAP_OK);
}
