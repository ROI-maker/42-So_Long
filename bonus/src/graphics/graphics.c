/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:44:03 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/29 22:20:22 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_player_eating(t_game *game, int y, int x)
{
	void	*img;

	img = NULL;
	if (game->player->direction == UP)
		img = game->graphics->up[1];
	else if (game->player->direction == DOWN)
		img = game->graphics->down[1];
	else if (game->player->direction == LEFT)
		img = game->graphics->left[1];
	else if (game->player->direction == RIGHT)
		img = game->graphics->right[1];
	mlx_put_image_to_window(game->graphics->mlx,
		game->graphics->wnd, img, x * IMG_PXL, y * IMG_PXL);
}

void	draw_player(t_game *game, t_player *player, t_map *map)
{
	void	*img;
	int		x;
	int		y;

	x = player->player_x;
	y = player->player_y;
	img = NULL;
	if (map->grid[y][x] == 'C')
	{
		draw_player_eating(game, y, x);
		return ;
	}
	if (player->direction == UP)
		img = game->graphics->up[0];
	else if (player->direction == DOWN)
		img = game->graphics->down[0];
	else if (player->direction == LEFT)
		img = game->graphics->left[0];
	else if (player->direction == RIGHT && player->not_finish_anim)
		img = game->graphics->not_exit_img;
	else if (player->direction == RIGHT)
		img = game->graphics->right[0];
	mlx_put_image_to_window(game->graphics->mlx,
		game->graphics->wnd, img, x * IMG_PXL, y * IMG_PXL);
}

//rend the map and items
void	draw_tile(t_game *game, int x, int y)
{
	char	cell;
	int		px;
	int		py;

	cell = game->map->grid[y][x];
	px = x * IMG_PXL;
	py = y * IMG_PXL;
	mlx_put_image_to_window(game->graphics->mlx,
		game->graphics->wnd, game->graphics->ground, px, py);
	if (cell == '1')
		mlx_put_image_to_window(game->graphics->mlx,
			game->graphics->wnd, game->graphics->wall, px, py);
	else if (cell == 'C')
		mlx_put_image_to_window(game->graphics->mlx,
			game->graphics->wnd, game->graphics->collectible, px, py);
	else if (cell == 'E' && game->map->c != 0)
		mlx_put_image_to_window(game->graphics->mlx,
			game->graphics->wnd, game->graphics->exit[0], px, py);
	else if (cell == 'E' && game->map->c == 0)
		mlx_put_image_to_window(game->graphics->mlx,
			game->graphics->wnd, game->graphics->exit[1], px, py);
	else if (cell == 'W')
		mlx_put_image_to_window(game->graphics->mlx,
			game->graphics->wnd, game->graphics->water, px, py);
}

//draw the moves count
void	draw_moves(t_game *game)
{
	char	*move_str;
	char	*display_str;

	move_str = ft_itoa(game->player->moves);
	display_str = ft_strjoin("Moves :", move_str);
	mlx_string_put(game->graphics->mlx, game->graphics->wnd,
		15, 25, COLOR, display_str);
	free(move_str);
	free(display_str);
}

void	partial_render(t_game *game, int old_x, int old_y)
{
	t_player	*player;
	t_map		*map;

	player = game->player;
	map = game->map;
	draw_tile(game, old_x, old_y);
	draw_tile(game, player->player_x, player->player_y);
	if (map->c == 0)
		draw_tile(game, map->exit_x, map->exit_y);
	draw_player(game, player, map);
	draw_tile(game, 0, 0);
	draw_tile(game, 1, 0);
	draw_moves(game);
	draw_timer(game);
	player->not_finish_anim = 0;
}
