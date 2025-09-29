/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:03:00 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/18 00:59:09 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../so_long.h"

typedef struct s_player		t_player;
typedef struct s_graphics	t_graphics;
typedef struct s_game		t_game;

typedef struct s_map
{
	int		fd;
	char	*filename;
	char	**grid;
	char	**copy;
	int		x;
	int		y;
	int		p;
	int		c;
	int		e;
	int		m;
	int		c_copy;
	int		e_copy;
}	t_map;

void	map_checker(t_map *map, t_game *game);
void	path_checker(t_map *map, t_player *player, t_game *game);
void	load_map_to_grid(t_map *map, t_game *game);

#endif
