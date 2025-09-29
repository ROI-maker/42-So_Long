/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:41:06 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/29 20:59:27 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_free_grid(char **grid, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static void	ft_free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->filename)
		free(map->filename);
	if (map->grid)
		ft_free_grid(map->grid, map->y);
	if (map->copy)
		ft_free_grid(map->copy, map->y);
	free(map);
}

static void	destroy_image_array(t_graphics *graphics, void *arr[2], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
			mlx_destroy_image(graphics->mlx, arr[i]);
		i++;
	}
}

static void	ft_free_graphics(t_graphics *graphics)
{
	if (!graphics)
		return ;
	if (graphics->ground)
	{
		mlx_destroy_image(graphics->mlx, graphics->ground);
		mlx_destroy_image(graphics->mlx, graphics->wall);
		mlx_destroy_image(graphics->mlx, graphics->collectible);
		mlx_destroy_image(graphics->mlx, graphics->win_image);
		mlx_destroy_image(graphics->mlx, graphics->lost_image);
		mlx_destroy_image(graphics->mlx, graphics->not_exit_img);
		mlx_destroy_image(graphics->mlx, graphics->water);
		destroy_image_array(graphics, graphics->exit, 2);
		destroy_image_array(graphics, graphics->up, 2);
		destroy_image_array(graphics, graphics->down, 2);
		destroy_image_array(graphics, graphics->right, 2);
		destroy_image_array(graphics, graphics->left, 2);
		destroy_image_array(graphics, graphics->ng_images, 2);
		destroy_image_array(graphics, graphics->digits, 10);
	}
	free(graphics);
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		free(game->player);
	if (game->player_name)
		free(game->player_name);
	ft_free_map(game->map);
	ft_free_graphics(game->graphics);
	free(game);
}
