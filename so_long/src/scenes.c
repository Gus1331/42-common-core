/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:23:43 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/07 23:07:36 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_scenes(t_game *game);
void	scene(t_game game, char *file_path);

void	handle_scenes(t_game *game)
{
	if (game->scene_id == 0)
		scene(*game, "media/scene00.png");
	else if (game->scene_id == 1)
		scene(*game, "media/scene01.png");
	else if (game->scene_id == 2)
		scene(*game, "media/scene02.png");
	else if (game->scene_id == 3)
		scene(*game, "media/scene03.png");
	else if (game->scene_id == 4)
		scene(*game, "media/scene04.png");
	else if (game->scene_id == 5 || game->scene_id == 12)
	{
		game->scene = false;
		load_map(game, get_element_position(game->map, 'P'));
	}
	else if (game->scene_id == 11)
		scene(*game, "media/scene11.png");
	else if (game->scene_id == 21)
		scene(*game, "media/scene21.png");
	else if (game->scene_id == 22)
		scene(*game, "media/scene99.png");
	else if (game->scene_id == 23)
		close_game(*game);
	game->scene_id++;
}

void	scene(t_game game, char *file_path)
{
	mlx_texture_t	*scene_tex;

	scene_tex = mlx_load_png(file_path);
	mlx_image_to_window(game.mlx,
		mlx_texture_to_image(game.mlx, scene_tex), 0, 0);
	mlx_delete_texture(scene_tex);
}
