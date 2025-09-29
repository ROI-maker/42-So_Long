/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:47:56 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/20 22:10:36 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

static void	move_right(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	next;

	x = player->player_x;
	y = player->player_y;
	next = map->grid[y][x + 1];
	if (next != '1')
	{
		if (next == 'C')
		{
			map->grid[y][x + 1] = '0';
			player->collected++;
			map->c--;
		}
		player->player_x++;
		player->direction = RIGHT;
		player->moves++;
		ft_printf("Moves : %d\n", player->moves);
		render_map(game);
		if (next == 'E' && map->c == 0)
			normal_exit(game);
	}
}

static void	move_left(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	next;

	x = player->player_x;
	y = player->player_y;
	next = map->grid[y][x - 1];
	if (next != '1')
	{
		if (next == 'C')
		{
			map->grid[y][x - 1] = '0';
			player->collected++;
			map->c--;
		}
		player->player_x--;
		player->direction = LEFT;
		player->moves++;
		ft_printf("Moves : %d\n", player->moves);
		render_map(game);
		if (next == 'E' && map->c == 0)
			normal_exit(game);
	}
}

static void	move_up(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	next;

	x = player->player_x;
	y = player->player_y;
	next = map->grid[y - 1][x];
	if (next != '1')
	{
		if (next == 'C')
		{
			map->grid[y - 1][x] = '0';
			player->collected++;
			map->c--;
		}
		player->player_y--;
		player->direction = UP;
		player->moves++;
		ft_printf("Moves : %d\n", player->moves);
		render_map(game);
		if (next == 'E' && map->c == 0)
			normal_exit(game);
	}
}

static void	move_down(t_game *game, t_map *map, t_player *player)
{
	int		x;
	int		y;
	char	next;

	x = player->player_x;
	y = player->player_y;
	next = map->grid[y + 1][x];
	if (next != '1')
	{
		if (next == 'C')
		{
			map->grid[y + 1][x] = '0';
			player->collected++;
			map->c--;
		}
		player->player_y++;
		player->direction = DOWN;
		render_map(game);
		player->moves++;
		ft_printf("Moves : %d\n", player->moves);
		if (next == 'E' && map->c == 0)
			normal_exit(game);
	}
}

int	handle_key(int keycode, t_game *game)
{
	t_map		*map;
	t_player	*player;

	map = game->map;
	player = game->player;
	if (keycode == RIGHT)
		move_right(game, map, player);
	else if (keycode == LEFT)
		move_left(game, map, player);
	else if (keycode == UP)
		move_up(game, map, player);
	else if (keycode == DOWN)
		move_down(game, map, player);
	else if (keycode == ESC)
		normal_exit(game);
	return (0);
}
