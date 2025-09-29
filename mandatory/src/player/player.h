/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:41:42 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/18 01:14:51 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../../so_long.h"

typedef struct s_player
{
	int		player_y;
	int		player_x;
	int		collected;
	int		moves;
	char	direction;
}	t_player;

typedef struct s_map		t_map;
typedef struct s_graphics	t_graphics;
typedef struct s_game		t_game;

void		find_player(t_map *map, t_player *player);

#endif
