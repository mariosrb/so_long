/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:44 by mario             #+#    #+#             */
/*   Updated: 2025/03/14 15:22:50 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

void	print_map_error(int error_code)
{
	if (error_code == ERR_NO_PLAYER)
		ft_putstr_fd("Error\nMap must have exactly one starting point (P)\n",
			2);
	else if (error_code == ERR_MULTI_PLAYER)
		ft_putstr_fd("Error\nMap has multiple starting points\n", 2);
	else if (error_code == ERR_NO_EXIT)
		ft_putstr_fd("Error\nMap must have exactly one exit (E)\n", 2);
	else if (error_code == ERR_MULTI_EXIT)
		ft_putstr_fd("Error\nMap has multiple exits\n", 2);
	else if (error_code == ERR_NO_COLLECT)
		ft_putstr_fd("Error\nMap must have at least one collectible (C)\n", 2);
	else if (error_code == ERR_INVALID_CHAR)
		ft_putstr_fd("Error\nMap contains invalid character\n", 2);
	else if (error_code == ERR_NOT_RECTANGLE)
		ft_putstr_fd("Error\nMap must be rectangular\n", 2);
	else if (error_code == ERR_NO_WALLS)
		ft_putstr_fd("Error\nMap must be surrounded by walls\n", 2);
	else if (error_code == ERR_MAP_TOO_SMALL)
		ft_putstr_fd("Error\nMap is too small\n", 2);
	else if (error_code == ERR_MEMORY)
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
	else if (error_code == ERR_NO_PATH)
		ft_putstr_fd("Error\nMap has no valid path\n", 2);
}

void	count_elements(t_map *map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	*p = 0;
	*e = 0;
	*c = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				(*p)++;
			else if (map->map[i][j] == 'E')
				(*e)++;
			else if (map->map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

int	validate_count(int p, int e, int c)
{
	if (p == 0)
		return (ERR_NO_PLAYER);
	if (p > 1)
		return (ERR_MULTI_PLAYER);
	if (e == 0)
		return (ERR_NO_EXIT);
	if (e > 1)
		return (ERR_MULTI_EXIT);
	if (c == 0)
		return (ERR_NO_COLLECT);
	return (0);
}

int	check_exit_reachable(char **filled_map, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'E')
			{
				if ((i > 0 && filled_map[i - 1][j] == 'F') || (i < map->height
						- 1 && filled_map[i + 1][j] == 'F') || (j > 0
						&& filled_map[i][j - 1] == 'F') || (j < map->width - 1
						&& filled_map[i][j + 1] == 'F'))
					return (1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
