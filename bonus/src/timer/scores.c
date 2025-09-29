/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:38:34 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/21 17:52:08 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

typedef struct
{
	char	name[50];
	long	time;
}	t_score;


void	save_score(t_game *game, long elapsed)
{
	FILE *file = fopen("scores.txt", "a");
	if (!file)
		return ;
	fprintf(file, "%s:%ld\n", game->player_name, elapsed);
	fclose(file);
}

static int	load_score(t_score score[], int max_score)
{
	int	count;

	FILE *file = fopen("scores.txt", "r");
	if (!file)
		return (0);
	count = 0;
	while (fscanf(file, "%49[^:]:%ld\n", score[count].name,
		&score[count].time) == 2)
	{
		count++;
		if (count >= max_score)
			break;
	}
	fclose(file);
	return (count);
}

static void	sort_score(t_score score[], int count)
{
	int	i;
	int	j;
	t_score	temp;
	
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (score[j].time > score[j+1].time)
			{
				temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	display_score(void)
{
	t_score	score[100];
	int		count;
	int		i;

	count = load_score(score, 100);
	if (count == 0)
	{
		ft_printf("Aucun score.\n");
		return ;
	}
	sort_score(score, count);
	printf("\n--- Scores triés ---\n");
	i = 0;
	while (i < count)
	{
		printf("%d. %s : %ld sec\n", i + 1, score[i].name, score[i].time);
        i++;
	}
	printf("-------------------\n");
}

