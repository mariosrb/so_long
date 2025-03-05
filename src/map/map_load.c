/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:41 by mario             #+#    #+#             */
/*   Updated: 2025/03/05 18:07:33 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	check_file_extension(char *file)
{
	char	*dot;

	if (!file)
		return (0);
	dot = ft_strrchr(file, '.');
	if (!dot)
		return (0);
	if (ft_strlen(dot) != 4)
		return (0);
	if (ft_strncmp(dot, ".ber", 4) != 0)
		return (0);
	return (1);
}

static int	count_line(char *file)
{
	int		fd;
	int		count_line;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

size_t	get_line_width(char *line)
{
	size_t	len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		return (len - 1);
	return (len);
}

static	int	handle_map_error(t_map *map, char *map_path)
{
	if (!check_file_extension(map_path))
		return (ft_putstr_fd("Error\nInvalid file extension. Must be .ber", 2)
			, 0);
	map->height = count_line(map_path);
	if (map->height <= 0)
		return (ft_putstr_fd("Error\nMemory allocation failed", 2), 0);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (ft_putstr_fd("Error\nMemory allocation failed", 2), 0);
	return (1);
}

int	map_load(t_map *map, char *map_path)
{
	int		fd;
	int		i;
	char	*line;

	if (!handle_map_error(map, map_path))
		return (0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nFailed to open map file", 2), 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[i] = line;
		if (i == 0)
			map->width = get_line_width(line);
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	close(fd);
	return (1);
}
