/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:50:27 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/04 04:13:20 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(char *msg, char **map);
void	game_error(char *msg, t_game game);

void	invalid_map(char *msg, char **map)
{
	ft_printf("Invalid map! %s\n", msg);
	if (map)
		ft_free_str_arr(map);
	exit(EXIT_FAILURE);
}

void	game_error(char *msg, t_game game)
{
	ft_printf("Game Error! %s\n", msg);
	if (game.map != NULL)
		ft_free_str_arr(game.map);
	if (game.mlx != NULL)
		mlx_terminate(game.mlx);
	if (game.textures.background != NULL)
		unload_textures(game.textures);
	exit(EXIT_FAILURE);
}
