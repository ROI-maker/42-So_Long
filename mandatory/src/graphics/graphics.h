/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:37:38 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/19 00:13:46 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "../../so_long.h"

# define IMG_PXL 64

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
}	t_graphics;

typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_game	t_game;

void		load_game_image(t_graphics *graphics, t_game *s_game);
void		render_map(t_game *game);

#endif