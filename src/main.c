/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:03:28 by mario             #+#    #+#             */
/*   Updated: 2025/02/27 17:19:19 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int ac, char **av)
{
    t_map map;
    int error_code;
    
    (void)ac;
    if (!map_load(&map, av[1]))
        return (1);
    printf("map loaded\n");
    error_code = validate_map(&map);
    if (error_code != MAP_OK)
    {
        free_char_tab(map.map);
        return (1);
    }
    //reste du programme

    free_char_tab(map.map);
    return (0);
}