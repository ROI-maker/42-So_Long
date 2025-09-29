/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:03:03 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/19 01:02:16 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*read_map_file(const char *filename, t_game *game, int *height)
{
	int		fd;
	char	*line;
	char	*raw_map;
	char	*tmp;

	raw_map = ft_strdup("");
	if (!raw_map)
		error_exit(game, "ERROR: strdup in read_map_file");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(game, "ERROR: open failed in read_map_file");
	line = get_next_line(fd);
	*height = 0;
	while (line != NULL)
	{
		tmp = ft_strjoin(raw_map, line);
		free(line);
		free(raw_map);
		raw_map = tmp;
		(*height)++;
		line = get_next_line(fd);
	}
	close(fd);
	return (raw_map);
}

void	load_map_to_grid(t_map *map, t_game *game)
{
	char	*raw_map;

	raw_map = read_map_file(map->filename, game, &map->y);
	map->grid = ft_split(raw_map, '\n');
	map->copy = ft_split(raw_map, '\n');
	if (!map->grid || !map->copy)
		error_exit(game, "ERROR: split in load_map_to_grid");
	free(raw_map);
}
