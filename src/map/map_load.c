/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:41 by mario             #+#    #+#             */
/*   Updated: 2025/02/25 22:32:35 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// On verifie si le fichier est bien en .ber
static int	check_file_extension(char *file)
{
    char    *dot;

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
	while ((line = get_next_line(fd)) != NULL)
	{
		count_line++;
		free(line);
	}
	close(fd);
	return (count_line);
}

int	map_load(t_map *map, char *map_path)
{
	int		fd;
	int		i;
	char	*line;
	
	if (!check_file_extension(map_path))
		return (ft_putstr_fd("Error\nInvalid file extension. Must be .ber", 2), 0);
	map->height = count_line(map_path);
	if (map->height <= 0)
		return (ft_putstr_fd("Error\nInvalid or empty map file", 2), 0);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (ft_putstr_fd("Error\nMemory allocation failed", 2), 0);
	if ((fd = open(map_path, O_RDONLY)) < 0)
		return (ft_putstr_fd("Error\nFailed to open map file", 2), 0);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[i] = line;
		if (i == 0)
			map->width = ft_strlen(line);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (1);
}

void    print_char_tab(char **tab)
{
    int i;

    i = 0;
    if (!tab)
    {
        ft_putstr_fd("Error: NULL pointer\n", 2);
        return;
    }
    while (tab[i])
    {
        ft_putstr_fd(tab[i], 1);
        ft_putchar_fd('\n', 1);
        i++;
    }
}

// int main (int ac, char **av)
// {
// 	t_map map;
//     (void)ac;
// 	printf("%d\n", check_file_extension(av[1]));
// 	printf("le nombre de ligne : %d\n", count_line(av[1]));
// 	map_load(&map, av[1]);
// 	print_char_tab(map.map);
// 	free_char_tab(map.map);
//     return (0);
// }
