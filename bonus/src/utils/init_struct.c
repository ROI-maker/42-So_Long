/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 00:58:10 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 14:06:02 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->player_y = 0;
	player->player_x = 0;
	player->collected = 0;
	player->moves = 0;
	player->direction = RIGHT;
	return (player);
}

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->fd = 0;
	map->filename = ft_strdup(filename);
	map->grid = NULL;
	map->copy = NULL;
	map->x = 0;
	map->y = 0;
	map->p = 0;
	map->c = 0;
	map->e = 0;
	map->m = 0;
	map->c_copy = 0;
	map->e_copy = 0;
	return (map);
}

t_graphics	*init_graphics(void)
{
	t_graphics	*graphics;

	graphics = ft_calloc(1, sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	return (graphics);
}

t_game	*init_game(t_player *play, t_graphics *graph, t_map *map, char *name)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->player = play;
	game->graphics = graph;
	game->start_time.tv_sec = 0;
	game->time_left = 45;
	game->player_name = ft_strdup(name);
	return (game);
}
