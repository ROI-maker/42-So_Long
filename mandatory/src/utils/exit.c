/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:04:10 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/30 14:51:35 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//to properly exit the program on errors
void	error_exit(t_game *game, char *msg)
{
	ft_free_all(game);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

//to properly exit the program
int	normal_exit(t_game *game)
{
	if (game->map->c == 0)
		ft_printf("You ate %d squares of grass in %d moves! Well done!\n",
			game->player->collected, game->player->moves);
	else
		ft_printf("You didn’t finish your game :'(\n");
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
