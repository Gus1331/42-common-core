/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:46:17 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/04 04:31:49 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game		game_init(char **map);
static void	update_max_map(t_game *game);
void		close_game(t_game game);

t_game	game_init(char **map)
{
	t_game	game;

	game.map = map;
	game.player = init_player(game);
	game.mlx = mlx_init(1152, 896, "Half Piece 🏴‍☠️", true);
	update_max_map(&game);
	if (!game.mlx)
		game_error("MLX error", game);
	load_textures(&game);
	ft_printf("loading map...\n");
	load_map(&game, game.player.position);
	ft_printf("Loop...\n");
	mlx_key_hook(game.mlx, key_hook, (void *)&game);
	mlx_loop(game.mlx);
	return (game);
}

static void	update_max_map(t_game *game)
{
	int	y;

	y = 0;
	game->max_x = ft_strlen(*(game->map));
	while (game->map[y])
		y++;
	game->max_y = y;
}

void	close_game(t_game game)
{
	ft_printf("Jogo finalizado com %d coletáveis\n", game.player.collectibles);
	if (game.map != NULL)
		ft_free_str_arr(game.map);
	if (game.mlx != NULL)
		mlx_terminate(game.mlx);
	if (game.textures.background != NULL)
		unload_textures(game.textures);
	exit(EXIT_SUCCESS);
}
