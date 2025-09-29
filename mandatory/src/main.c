/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:39:46 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/29 20:45:55 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_all(t_player **play, t_graphics **graph, t_map **map, char *fn)
{
	*map = init_map(fn);
	*play = init_player();
	*graph = init_graphics();
}

void	create_and_check_map(t_map *map, t_player *player, t_game *game)
{
	load_map_to_grid(map, game);
	map_checker(map, game);
	path_checker(map, player, game);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;
	t_graphics	*graphics;
	t_game		*game;

	if (argc != 2)
		return (1);
	init_all(&player, &graphics, &map, argv[1]);
	game = init_game(player, graphics, map);
	if (!game || !game->map || !game->player || !game->graphics)
	{
		ft_free_all(game);
		ft_putendl_fd("Error: init of struct failed", 2);
		return (1);
	}
	create_and_check_map(map, player, game);
	graphics->mlx = mlx_init();
	graphics->wnd = mlx_new_window(graphics->mlx, map->x
			* IMG_PXL, map->y * IMG_PXL, "so_long");
	load_game_image(graphics, game);
	render_map(game);
	mlx_hook(graphics->wnd, 17, 0, mlx_hook_exit, game);
	mlx_key_hook(graphics->wnd, handle_key, game);
	mlx_loop(graphics->mlx);
	return (0);
}
