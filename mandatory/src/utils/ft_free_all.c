/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:41:06 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/30 14:58:00 by sclaeys          ###   ########.fr       */
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

static void	destroy_image_array(t_graphics *graphics, void *arr[2])
{
	int	i;

	i = 0;
	while (i < 2)
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
		destroy_image_array(graphics, graphics->exit);
		destroy_image_array(graphics, graphics->up);
		destroy_image_array(graphics, graphics->down);
		destroy_image_array(graphics, graphics->right);
		destroy_image_array(graphics, graphics->left);
	}
	if (graphics->wnd)
		mlx_destroy_window(graphics->mlx, graphics->wnd);
	if (graphics->mlx)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
	}
	free(graphics);
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		free(game->player);
	ft_free_map(game->map);
	ft_free_graphics(game->graphics);
	free(game);
}
