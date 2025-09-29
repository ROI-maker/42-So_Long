/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:30:50 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/20 14:32:05 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include "../../so_long.h"

# define RIGHT  100
# define LEFT   97
# define UP     119
# define DOWN   115
# define ESC	65307
# define ARROW_LEFT   65361
# define ARROW_UP     65362
# define ARROW_RIGHT  65363
# define ARROW_DOWN   65364

typedef struct s_player		t_player;
typedef struct s_map		t_map;
typedef struct s_graphics	t_graphics;
typedef struct s_game		t_game;

//gameplay.c
int		handle_key(int keycode, t_game *game);

//gameplay2.c
void	update_player_image(char cell, int x, int y, t_game *game);

#endif