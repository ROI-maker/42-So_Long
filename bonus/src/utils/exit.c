/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:04:10 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/30 08:55:50 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//to properly exit the program on errors
void	error_exit(t_game *game, char *msg)
{
	ft_putendl_fd(msg, 2);
	ft_free_all(game);
	exit(EXIT_FAILURE);
}

int	water_exit(t_game *game)
{
	mlx_put_image_to_window(game->graphics->mlx, game->graphics->wnd,
		game->graphics->lost_image, 0, 0);
	mlx_do_sync(game->graphics->mlx);
	usleep(1800000);
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

//to properly exit the program
int	normal_exit(t_game *game)
{
	struct timeval	end;
	long			elapsed;

	if (game->map->c == 0)
	{
		gettimeofday(&end, NULL);
		elapsed = (end.tv_sec - game->start_time.tv_sec)
			+ (end.tv_usec - game->start_time.tv_usec) / 1000000;
		mlx_put_image_to_window(game->graphics->mlx, game->graphics->wnd,
			game->graphics->win_image, 0, 0);
		mlx_do_sync(game->graphics->mlx);
		usleep(1000000);
		save_score(game, elapsed);
		display_score();
	}
	else
	{
		mlx_put_image_to_window(game->graphics->mlx, game->graphics->wnd,
			game->graphics->lost_image, 0, 0);
		mlx_do_sync(game->graphics->mlx);
		usleep(1000000);
	}
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}

//Function to properly exit the program with mlx_hook()
int	mlx_hook_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_free_all(game);
	exit(EXIT_SUCCESS);
	return (0);
}
