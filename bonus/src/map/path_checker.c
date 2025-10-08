/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 02:02:48 by sclaeys           #+#    #+#             */
/*   Updated: 2025/10/08 21:02:51 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	flood_fill(t_map *map, int x, int y)
{
	char	cell;

	if (x < 0 || y < 0 || x >= map->x || y >= map->y)
		return ;
	cell = map->copy[y][x];
	if (cell == '1')
		return ;
	if (cell == 'W')
		return ;
	if (cell == 'C')
		map->c_copy--;
	else if (cell == 'E')
		map->e_copy--;
	map->copy[y][x] = '1';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static void	setup_path_checker(t_map *map, t_player *player)
{
	map->c_copy = map->c;
	map->e_copy = map->e;
	find_player(map, player);
}

void	path_checker(t_map *map, t_player *player, t_game *game)
{
	setup_path_checker(map, player);
	flood_fill(map, player->player_x, player->player_y);
	if (map->c_copy != 0 || map->e_copy != 0)
		error_exit(game, "ERROR: No path is set");
}
