/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:03:28 by mario             #+#    #+#             */
/*   Updated: 2025/03/04 20:02:43 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int handle_close(void *param)
{
    exit_game((t_game *)param);
    return (0);
}

static void setup_hooks(t_game *game)
{
    // Hook pour les touches du clavier
    mlx_hook(game->graphics->window, 2, 1L<<0, key_handler, game);
    
    // Hook pour le bouton de fermeture de la fenêtre (croix rouge)
    mlx_hook(game->graphics->window, 17, 0, handle_close, game);
}

int main(int ac, char **av)
{
    t_game *game;
    
    // Vérification des arguments
    if (ac != 2)
    {
        ft_putstr_fd("Error\nUsage: ./so_long [map_file.ber]\n", 2);
        return (1);
    }
    
    // Vérification de l'extension .ber
    if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
    {
        ft_putstr_fd("Error\nInvalid map file extension (must be .ber)\n", 2);
        return (1);
    }
    
    // Initialisation du jeu
    game = init_game(av[1]);
    if (!game)
        return (1);
    
    // Configuration des hooks pour les événements
    setup_hooks(game);
    
    // Rendu initial de la carte
    render_map(game->graphics, game->map);
    
    // Affichage du compteur de mouvements initial
    printf("Moves: 0\n");
    
    // Lancement de la boucle principale
    mlx_loop(game->graphics->mlx);
    
    // Note: Ce code ne sera jamais atteint car exit_game() appellera exit()
    return (0);
}
