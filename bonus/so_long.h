/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:03:35 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/29 16:32:26 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# include <time.h>
# include <sys/time.h>

# include "../includes/minilib/libft.h"
# include "../includes/minilib/ft_printf/ft_printf.h"
# include "../includes/minilib/get_next_line/get_next_line.h"
# include "../includes/minilibx-linux/mlx.h"
# include "src/map/map.h"
# include "src/player/player.h"
# include "src/graphics/graphics.h"
# include "src/gameplay/gameplay.h"
# include "src/timer/timer.h"

# define WND_NAME "so_long"

typedef struct s_player		t_player;
typedef struct s_map		t_map;
typedef struct s_graphics	t_graphics;

typedef struct s_game
{
	t_map			*map;
	t_player		*player;
	t_graphics		*graphics;
	struct timeval	start_time;
	int				time_left;
	char			*player_name;
}	t_game;

//ft_free_all.c
void		ft_free_all(t_game *game);

//exit.c
int			mlx_hook_exit(void *param);
void		error_exit(t_game *game, char *msg);
int			normal_exit(t_game *game);
int			water_exit(t_game *game);

//init_struct.c
t_graphics	*init_graphics(void);
t_map		*init_map(char *filename);
t_player	*init_player(void);
t_game		*init_game(t_player *play, t_graphics *graph, t_map *map, char *name);

#endif