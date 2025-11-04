/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 04:35:18 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/04 04:42:09 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			load_images(t_game *game);
void		reload_images(t_game *game);
static int	check_images(t_images *images);

int	load_images(t_game *game)
{
	t_images	images;
	t_texture	t;

	images
		= (t_images){NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	t = game->textures;
	images.background = mlx_texture_to_image(game->mlx, t.background);
	images.collectibles = mlx_texture_to_image(game->mlx, t.collectibles);
	images.end = mlx_texture_to_image(game->mlx, t.end);
	images.water = mlx_texture_to_image(game->mlx, t.water);
	images.wall = mlx_texture_to_image(game->mlx, t.wall);
	images.player_down = mlx_texture_to_image(game->mlx, t.player_down);
	images.player_up = mlx_texture_to_image(game->mlx, t.player_up);
	images.player_left = mlx_texture_to_image(game->mlx, t.player_left);
	images.player_right = mlx_texture_to_image(game->mlx, t.player_right);
	game->images = images;
	return (check_images(&(game->images)));
}

void	reload_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->images.background);
	mlx_delete_image(game->mlx, game->images.collectibles);
	mlx_delete_image(game->mlx, game->images.end);
	mlx_delete_image(game->mlx, game->images.water);
	mlx_delete_image(game->mlx, game->images.wall);
	mlx_delete_image(game->mlx, game->images.player_down);
	mlx_delete_image(game->mlx, game->images.player_up);
	mlx_delete_image(game->mlx, game->images.player_left);
	mlx_delete_image(game->mlx, game->images.player_right);
	if (load_images(game) == 0)
		game_error("Error to reload frame", *game);
}

static int	check_images(t_images *images)
{
	if (!images->background
		|| !images->collectibles
		|| !images->end
		|| !images->water
		|| !images->wall
		|| !images->player_down
		|| !images->player_up
		|| !images->player_left
		|| !images->player_right)
		return (0);
	return (1);
}
