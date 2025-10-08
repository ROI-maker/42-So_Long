/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:03:03 by sclaeys           #+#    #+#             */
/*   Updated: 2025/10/08 20:57:56 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*read_map_file(const char *filename, t_game *game, int *height)
{
	int		fd;
	char	*line;
	char	*raw_map;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(game, "ERROR: open failed in read_map_file");
	raw_map = ft_strdup("");
	if (!raw_map)
		error_exit(game, "ERROR: strdup in read_map_file");
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

static int	check_raw_map(char *raw_map)
{
	int	i;

	i = 0;
	if (raw_map[i] == '\n')
		return (0);
	while (raw_map[i])
	{
		if (raw_map[i] == '\n' && raw_map[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	load_map_to_grid(t_map *map, t_game *game)
{
	char	*raw_map;

	raw_map = read_map_file(map->filename, game, &map->y);
	if (!check_raw_map(raw_map))
	{
		free(raw_map);
		ft_putendl_fd("ERROR: First line must be the top of the map", 2);
		ft_putendl_fd("ERROR: Last line must be the bottom of the map", 2);
		error_exit(game, "ERROR: The map cannot be split in two");
	}
	map->grid = ft_split(raw_map, '\n');
	map->copy = ft_split(raw_map, '\n');
	if (!map->grid || !map->copy)
	{
		free(raw_map);
		error_exit(game, "ERROR: split in load_map_to_grid");
	}
	free(raw_map);
}
