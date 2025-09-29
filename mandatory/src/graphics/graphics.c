/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:44:03 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/19 00:17:25 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	load_image(void *mlx, void **img, const char *path, t_game *game)
{
	int	pxl;

	pxl = IMG_PXL;
	*img = mlx_xpm_file_to_image(mlx, (char *)path, &pxl, &pxl);
	if (!*img)
		error_exit(game, "ERROR: Failed to load images");
}

//Link the pointers to the images and to the graphical interface
void	load_game_image(t_graphics *graphics, t_game *game)
{
	load_image(graphics->mlx, &graphics->ground, "assets/ground.xpm", game);
	load_image(graphics->mlx, &graphics->wall, "assets/wall.xpm", game);
	load_image(graphics->mlx, &graphics->collectible,
		"assets/collectible.xpm", game);
	load_image(graphics->mlx, &graphics->exit[0], "assets/exit1.xpm", game);
	load_image(graphics->mlx, &graphics->exit[1], "assets/exit2.xpm", game);
	load_image(graphics->mlx, &graphics->up[0], "assets/up1.xpm", game);
	load_image(graphics->mlx, &graphics->up[1], "assets/up2.xpm", game);
	load_image(graphics->mlx, &graphics->down[0], "assets/down1.xpm", game);
	load_image(graphics->mlx, &graphics->down[1], "assets/down2.xpm", game);
	load_image(graphics->mlx, &graphics->right[0], "assets/right1.xpm", game);
	load_image(graphics->mlx, &graphics->right[1], "assets/right2.xpm", game);
	load_image(graphics->mlx, &graphics->left[0], "assets/left1.xpm", game);
	load_image(graphics->mlx, &graphics->left[1], "assets/left2.xpm", game);
}

//rend the player
static void	draw_player(t_game *game)
{
	void	*img;
	int		px;
	int		py;

	px = game->player->player_x * IMG_PXL;
	py = game->player->player_y * IMG_PXL;
	img = NULL;
	if (game->player->direction == UP)
		img = game->graphics->up[0];
	else if (game->player->direction == DOWN)
		img = game->graphics->down[0];
	else if (game->player->direction == LEFT)
		img = game->graphics->left[0];
	else if (game->player->direction == RIGHT)
		img = game->graphics->right[0];
	mlx_put_image_to_window(game->graphics->mlx,
		game->graphics->wnd, img, px, py);
}

//rend the map and items
static void	draw_tile(t_game *game, int x, int y)
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
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->y)
	{
		x = 0;
		while (x < game->map->x)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	draw_player(game);
}
