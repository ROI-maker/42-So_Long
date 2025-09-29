/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:37:22 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/29 21:02:01 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	draw_digits(t_game *game, int time_left, int x_pos, int y_pos)
{
	int	tens;
	int	units;

	if (time_left >= 10)
	{
		tens = time_left / 10;
		mlx_put_image_to_window(game->graphics->mlx,
			game->graphics->wnd,
			game->graphics->digits[tens],
			x_pos, y_pos);
		x_pos += IMG_PXL;
	}
	units = time_left % 10;
	mlx_put_image_to_window(game->graphics->mlx,
		game->graphics->wnd,
		game->graphics->digits[units],
		x_pos, y_pos);
}

void	draw_timer(t_game *game)
{
	int	x_pos;
	int	y_pos;
	int	time_left;
	int	digits_count;
	int	total_width;

	y_pos = (game->map->y * IMG_PXL) - IMG_PXL;
	time_left = game->time_left;
	if (time_left < 10)
		digits_count = 1;
	else
		digits_count = 2;
	total_width = digits_count * IMG_PXL;
	x_pos = ((game->map->x * IMG_PXL) / 2) - (total_width / 2);
	draw_digits(game, time_left, x_pos, y_pos);
}

void	display_newgame_images(t_game *game)
{
	mlx_put_image_to_window(game->graphics->mlx, game->graphics->wnd,
		game->graphics->ng_images[0], 0, 0);
	usleep(1300000);
	mlx_clear_window(game->graphics->mlx, game->graphics->wnd);
	mlx_put_image_to_window(game->graphics->mlx, game->graphics->wnd,
		game->graphics->ng_images[1], 0, 0);
	usleep(1300000);
}

void	render_map_newgame(t_game *game)
{
	int			x;
	int			y;
	t_player	*player;
	t_map		*map;

	player = game->player;
	map = game->map;
	x = 0;
	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			draw_tile(game, x, y);
			x++;
			usleep(5000);
		}
		y++;
	}
	draw_player(game, player, map);
	player->not_finish_anim = 0;
}
