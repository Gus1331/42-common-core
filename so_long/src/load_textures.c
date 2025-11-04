/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:05:24 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/04 04:36:16 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		load_textures(t_game *game);
void		unload_textures(t_texture textures);
static int	check_textures(t_texture *textures);

void	load_textures(t_game *game)
{
	t_texture	textures;

	textures
		= (t_texture){NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	textures.background = mlx_load_png("./textures/background.png");
	textures.collectibles = mlx_load_png("./textures/collectibles.png");
	textures.end = mlx_load_png("./textures/end.png");
	textures.water = mlx_load_png("./textures/water.png");
	textures.wall = mlx_load_png("./textures/wall.png");
	textures.player_down = mlx_load_png("./textures/mm-f.png");
	textures.player_up = mlx_load_png("./textures/mm-b.png");
	textures.player_left = mlx_load_png("./textures/mm-l.png");
	textures.player_right = mlx_load_png("./textures/mm-r.png");
	game->textures = textures;
	if (check_textures(&textures) == 0)
		unload_textures(textures);
	else if (load_images(game) == 0)
		game_error("Failed to parse textures!", *game);
}

void	unload_textures(t_texture textures)
{
	mlx_delete_texture(textures.background);
	mlx_delete_texture(textures.collectibles);
	mlx_delete_texture(textures.end);
	mlx_delete_texture(textures.water);
	mlx_delete_texture(textures.wall);
	mlx_delete_texture(textures.player_down);
	mlx_delete_texture(textures.player_up);
	mlx_delete_texture(textures.player_left);
	mlx_delete_texture(textures.player_right);
}

static int	check_textures(t_texture *textures)
{
	if (!textures->background
		|| !textures->collectibles
		|| !textures->end
		|| !textures->water
		|| !textures->wall
		|| !textures->player_down
		|| !textures->player_up
		|| !textures->player_left
		|| !textures->player_right)
		return (0);
	return (1);
}
