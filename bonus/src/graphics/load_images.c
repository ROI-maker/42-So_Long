/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:12:02 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 16:28:29 by sclaeys          ###   ########.fr       */
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

static void	load_digits_images(t_graphics *graphics, t_game *game)
{
	load_image(graphics->mlx, &graphics->digits[0], "assets/0.xpm", game);
	load_image(graphics->mlx, &graphics->digits[1], "assets/1.xpm", game);
	load_image(graphics->mlx, &graphics->digits[2], "assets/2.xpm", game);
	load_image(graphics->mlx, &graphics->digits[3], "assets/3.xpm", game);
	load_image(graphics->mlx, &graphics->digits[4], "assets/4.xpm", game);
	load_image(graphics->mlx, &graphics->digits[5], "assets/5.xpm", game);
	load_image(graphics->mlx, &graphics->digits[6], "assets/6.xpm", game);
	load_image(graphics->mlx, &graphics->digits[7], "assets/7.xpm", game);
	load_image(graphics->mlx, &graphics->digits[8], "assets/8.xpm", game);
	load_image(graphics->mlx, &graphics->digits[9], "assets/9.xpm", game);
}

//Link the pointers to the images and to the graphical interface
void	load_game_images(t_graphics *graphics, t_game *game)
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
	load_image(graphics->mlx, &graphics->win_image, "assets/win.xpm", game);
	load_image(graphics->mlx, &graphics->lost_image, "assets/lost.xpm", game);
	load_image(graphics->mlx, &graphics->not_exit_img,
		"assets/finish.xpm", game);
	load_image(graphics->mlx, &graphics->water, "assets/water.xpm", game);
	load_image(graphics->mlx, &graphics->ng_images[0],
		"assets/start1.xpm", game);
	load_image(graphics->mlx, &graphics->ng_images[1],
		"assets/start2.xpm", game);
	load_digits_images(graphics, game);
}
