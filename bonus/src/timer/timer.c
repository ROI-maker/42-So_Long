/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:35:08 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 14:41:57 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

void	start_timer(t_game *game)
{
	gettimeofday(&game->start_time, NULL);
	game->time_left = 45;
}

int	update_timer(t_game *game)
{
	struct timeval	current_time;
	long			elapsed;

	gettimeofday(&current_time, NULL);
	elapsed = (current_time.tv_sec - game->start_time.tv_sec)
	+ (current_time.tv_usec - game->start_time.tv_usec) / 1000000;
	game->time_left = 45 - elapsed;
	if (game->time_left <= 0)
	{
		normal_exit(game);
		return (1);
	}
	return (0);
}

