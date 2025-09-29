/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:40:46 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/20 16:25:06 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

//used in floodfill and for initialise the player position
void	find_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->grid[y][x] == 'P')
			{
				player->player_y = y;
				player->player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_exit(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->grid[y][x] == 'E')
			{
				map->exit_y = y;
				map->exit_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
