/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:37:38 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 16:23:37 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "../../so_long.h"

# define IMG_PXL 64
# define COLOR 0xFFFFFF

typedef struct s_graphics
{
	void	*mlx;
	void	*wnd;
	void	*ground;
	void	*wall;
	void	*exit[2];
	void	*up[2];
	void	*down[2];
	void	*right[2];
	void	*left[2];
	void	*collectible;
	void	*win_image;
	void	*lost_image;
	void	*not_exit_img;
	void	*water;
	void	*ng_images[2];
	void	*digits[10];
}	t_graphics;

typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_game	t_game;

//load_images.c
void		load_game_images(t_graphics *graphics, t_game *s_game);

//graphics.c
void		partial_render(t_game *game, int old_x, int old_y);
void		draw_tile(t_game *game, int x, int y);
void		draw_player(t_game *game, t_player *player, t_map *map);
void		draw_player_eating(t_game *game, int y, int x);

//graphics_utils.c
void		render_map_newgame(t_game *game);
void		display_newgame_images(t_game *game);
void		draw_timer(t_game *game);

#endif