/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:47:56 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 16:37:16 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

static void	move_right(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	new_cell;
	char	actual_cell;

	x = player->player_x;
	y = player->player_y;
	actual_cell = map->grid[y][x];
	new_cell = map->grid[y][x + 1];
	update_timer(game);
	if (new_cell != '1')
	{
		player->player_x++;
		player->moves++;
		player->direction = RIGHT;
		update_player_image(actual_cell, x, y, game);
		if (new_cell == 'W')
			water_exit(game);
		if (new_cell == 'E' && map->c != 0)
			player->not_finish_anim = 1;
		partial_render(game, x, y);
		if (new_cell == 'E' && map->c == 0)
			normal_exit(game);
	}
}

static void	move_left(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	new_cell;
	char	actual_cell;

	x = player->player_x;
	y = player->player_y;
	actual_cell = map->grid[y][x];
	new_cell = map->grid[y][x - 1];
	update_timer(game);
	if (new_cell != '1')
	{
		player->player_x--;
		player->moves++;
		player->direction = LEFT;
		update_player_image(actual_cell, x, y, game);
		if (new_cell == 'W')
			water_exit(game);
		if (new_cell == 'E' && map->c != 0)
			player->not_finish_anim = 1;
		partial_render(game, x, y);
		if (new_cell == 'E' && map->c == 0)
			normal_exit(game);
	}
}

static void	move_up(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	new_cell;
	char	actual_cell;

	x = player->player_x;
	y = player->player_y;
	actual_cell = map->grid[y][x];
	new_cell = map->grid[y - 1][x];
	update_timer(game);
	if (new_cell != '1')
	{
		player->player_y--;
		player->moves++;
		player->direction = UP;
		update_player_image(actual_cell, x, y, game);
		if (new_cell == 'W')
			water_exit(game);
		if (new_cell == 'E' && map->c != 0)
			player->not_finish_anim = 1;
		partial_render(game, x, y);
		if (new_cell == 'E' && map->c == 0)
			normal_exit(game);
	}
}

static void	move_down(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	new_cell;
	char	actual_cell;

	x = player->player_x;
	y = player->player_y;
	actual_cell = map->grid[y][x];
	new_cell = map->grid[y + 1][x];
	update_timer(game);
	if (new_cell != '1')
	{
		player->player_y++;
		player->moves++;
		player->direction = DOWN;
		update_player_image(actual_cell, x, y, game);
		if (new_cell == 'W')
			water_exit(game);
		if (new_cell == 'E' && map->c != 0)
			player->not_finish_anim = 1;
		partial_render(game, x, y);
		if (new_cell == 'E' && map->c == 0)
			normal_exit(game);
	}
}

int	handle_key(int keycode, t_game *game)
{
	t_map		*map;
	t_player	*player;

	map = game->map;
	player = game->player;
	if (keycode == RIGHT || keycode == ARROW_RIGHT)
		move_right(game, map, player);
	else if (keycode == LEFT || keycode == ARROW_LEFT)
		move_left(game, map, player);
	else if (keycode == UP || keycode == ARROW_UP)
		move_up(game, map, player);
	else if (keycode == DOWN || keycode == ARROW_DOWN)
		move_down(game, map, player);
	else if (keycode == ESC)
		normal_exit(game);
	return (0);
}
