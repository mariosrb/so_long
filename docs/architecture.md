## Détails des Modules et Fichiers

### 1. `src/`

Ce dossier contient l'ensemble du code source du projet organisé en sous-modules :

- **main.c**  
  Point d'entrée du programme. Il initialise le jeu, charge la carte et lance la boucle principale.

#### a. Module **game/**
- **game_init.c**  
  - Initialise la structure globale du jeu.
  - Crée la fenêtre graphique et charge la carte initiale.
  - Initialise d'autres paramètres (compteur de mouvements, état du jeu, etc.).y

- **game_loop.c**  
  - Contient la boucle principale qui gère les entrées utilisateur.
  - Met à jour l'état du jeu et appelle le rendu graphique à chaque itération.

- **game_utils.c**  
  - Regroupe des fonctions utilitaires pour le module game.
  - Peut inclure des fonctions de mise à jour de l'état global ou de comptage des mouvements.

#### b. Module **map/**
- **map_load.c**  
  - Charge la carte depuis un fichier au format **.ber**.
  - Transforme le contenu du fichier en une structure (tableau de chaînes, etc.) permettant une manipulation facile.

- **map_validate.c**  
  - Vérifie que la carte respecte les règles établies :
    - Carte rectangulaire avec des dimensions cohérentes.
    - Bordure uniquement constituée de murs.
    - Existence d'un unique point de départ (`P`), d'une unique sortie (`E`) et d'au moins un collectible (`C`).
    - Existence d'un chemin valide pour atteindre la sortie en collectant tous les objets.

- **map_render.c**  
  - Traduit les données de la carte en éléments graphiques.
  - Envoie les informations à MiniLibX pour afficher correctement la carte.

#### c. Module **player/**
- **player_move.c**  
  - Gère les déplacements du joueur en réponse aux entrées clavier.
  - Vérifie que le mouvement est permis (pas de collision avec un mur).

- **player_collect.c**  
  - Gère la logique de collecte des objets.
  - Met à jour la carte et le compteur de mouvement lorsque le joueur collecte un objet.

#### d. Module **graphics/**
- **graphics_init.c**  
  - Initialise le contexte graphique avec MiniLibX.
  - Crée la fenêtre et charge les textures/sprites nécessaires.

- **graphics_render.c**  
  - Responsable du rendu visuel de tous les éléments du jeu (carte, personnages, objets).
  - Rafraîchit l'affichage en fonction de l'état du jeu.

- **graphics_utils.c**  
  - Fournit des fonctions supplémentaires pour manipuler les images (redimensionnement, animations, etc.).

#### e. Module **utils/**
- **error_handling.c**  
  - Centralise la gestion des erreurs : affichage de messages explicites et arrêt du programme proprement en cas de problème.
  
- **memory_management.c**  
  - Gère l'allocation et la libération de mémoire afin d'éviter les fuites.
  - Assure le nettoyage complet des ressources lors de la fermeture du programme.

### 2. `include/`

Ce dossier regroupe tous les fichiers d'en-tête (.h) qui déclarent les fonctions, structures et constantes utilisées par les différents modules.

- **so_long.h**  
  - Fichier d'inclusion central qui inclut tous les autres headers (`game.h`, `map.h`, `player.h`, `graphics.h`, `utils.h`).
  - Permet d'avoir un point d'inclusion unique pour tous les fichiers sources.

- **game.h, map.h, player.h, graphics.h, utils.h**  
  - Ces headers contiennent respectivement les prototypes de fonctions et structures spécifiques à chaque module.

### 3. `lib/`

- **libft/**  
  - Contient la bibliothèque *libft*, utilisée pour compléter les fonctions standards en C (manipulation de chaînes de caractères, listes, etc.).
  - Elle est compilée et liée lors de la compilation du projet via le Makefile.

### 4. `assets/`

Ce dossier stocke toutes les ressources externes utilisées par le jeu :

- **images/**  
  - Textures, sprites et autres images graphiques utilisées pour dessiner l'interface et les éléments du jeu.


### 5. `docs/`

- **architecture.md**  
  - Ce document qui décrit l'architecture du projet.

### 6. `tests/`

Ce dossier contient des fichiers de tests unitaires et d'intégration, permettant de vérifier le bon fonctionnement des modules.

- **test_map.c**  
  - Tests visant à s'assurer que le module map charge, valide et rend la carte correctement.

- **test_player.c**  
  - Tests pour vérifier les fonctionnalités de déplacement et de collecte du module player.

### 7. Fichiers à la Racine

- **Makefile**  
  - Fichier de compilation automatique.
  - Gère la compilation des fichiers sources, la création des exécutables et la gestion des bibliothèques externes (comme libft).
  - Inclut les règles `all`, `clean`, `fclean` et `re`.

- **README.md**  
  - Fournit une introduction générale au projet.
  - Explique comment compiler et exécuter le jeu, ainsi que les fonctionnalités principales.

## Conclusion

L'architecture du projet **so_long** repose sur une séparation claire des responsabilités :
- **src/** regroupe le code source organisé en modules fonctionnels,
- **include/** centralise les déclarations grâce à des headers dédiés,
- **lib/**, **assets/**, **docs/** et **tests/** assurent respectivement la gestion des bibliothèques externes, des ressources, de la documentation et de la vérification du bon fonctionnement du projet.


