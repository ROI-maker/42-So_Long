/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:40:46 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/18 23:37:44 by sclaeys          ###   ########.fr       */
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
