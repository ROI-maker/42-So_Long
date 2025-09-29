/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:30:43 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/20 15:07:52 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// Check if the file extension is .ber
static void	file_checker(t_map *map, t_game *game)
{
	if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
		error_exit(game, "ERROR: Bad file extension.");
}

// Check if the map is a rectangle.
static void	size_checker(t_map *map, t_game *game)
{
	int	row;
	int	line_length;

	if (map ->y == 0)
		error_exit(game, "ERROR: Map is empty.");
	line_length = ft_strlen(map->grid[0]);
	row = 0;
	while (row < map->y)
	{
		if ((int)ft_strlen(map->grid[row]) != line_length)
			error_exit(game, "ERROR: Map is not a rectangle.");
		row++;
	}
	map->x = line_length;
}

//Check if the map contains only the allowed characters 
//and their correct counts
static void	char_checker(t_map *map, t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->y)
	{
		col = 0;
		while (col < map->x)
		{
			if (map->grid[row][col] == 'P')
				map->p += 1;
			else if (map->grid[row][col] == 'E')
				map->e += 1;
			else if (map->grid[row][col] == 'C')
				map->c += 1;
			else if (!(map->grid[row][col] == '0' || map->grid[row][col] == '1'
				|| map->grid[row][col] == 'W'))
				error_exit(game, "ERROR: Map is invalid.");
			col++;
		}
		row++;
	}
	if (map->c < 1 || map ->e != 1 || map ->p != 1)
		error_exit(game, "ERROR: Map is invalid.");
}

//Check that the map is completely surrounded by walls
static void	wall_checker(t_map *map, t_game *game)
{
	int	row;
	int	col;

	col = 0;
	while (col < map->x)
	{
		if (map->grid[0][col] != '1')
			error_exit(game, "ERROR: Map is not surrounded by walls(TOP).");
		col++;
	}
	row = 1;
	while (row < map->y -1)
	{
		if ((map->grid[row][0] != '1') || (map->grid[row][map->x - 1] != '1'))
			error_exit(game, "ERROR: Map is not surrounded by walls(SIDE).");
		row++;
	}
	col = 0;
	while (col < map->x)
	{
		if (map->grid[map->y - 1][col] != '1')
			error_exit(game, "ERROR: Map is not surrounded by walls(BOTT).");
		col++;
	}
}

void	map_checker(t_map *map, t_game *game)
{
	file_checker(map, game);
	size_checker(map, game);
	char_checker(map, game);
	wall_checker(map, game);
}
