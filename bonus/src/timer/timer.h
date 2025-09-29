/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:33:38 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 14:40:30 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include "../../so_long.h"

//timer.c
void	start_timer(t_game *game);
int		update_timer(t_game *game);

//scores.c
void	save_score(t_game *game, long elapsed);
void	display_score();


#endif