/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:31:11 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/20 14:32:51 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gameplay.h"

void	update_player_image(char cell, int x, int y, t_game *game)
{
	if (cell == 'C')
	{
		game->map->grid[y][x] = '0';
		game->player->collected++;
		game->map->c--;
	}
}
