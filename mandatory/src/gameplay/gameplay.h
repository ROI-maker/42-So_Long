/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:30:50 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/18 01:00:31 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include "../../so_long.h"

# define RIGHT   100
# define LEFT    97
# define UP      119
# define DOWN    115
# define ESC     65307

typedef struct s_player		t_player;
typedef struct s_map		t_map;
typedef struct s_graphics	t_graphics;
typedef struct s_game		t_game;

int		handle_key(int keycode, t_game *game);

#endif