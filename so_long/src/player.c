/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:41:25 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/06 04:43:51 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player			init_player(t_game game);
void				move(t_game *game, t_head direction);
static int			activate_ending(t_game *game);
static void			move_player(t_game *game, t_position destiny);
static t_position	calculate_destiny(t_position player_pos, t_head direction);

t_player	init_player(t_game game)
{
	t_player	player;

	player.position = get_element_position(game.map, 'P');
	player.head = DOWN;
	player.collectibles = 0;
	player.moves = 0;
	return (player);
}

void	move(t_game *game, t_head direction)
{
	t_position	des;

	if (game->player.head != direction)
	{
		game->player.head = direction;
		load_map(game, game->player.position);
		return ;
	}
	des = calculate_destiny(game->player.position, direction);
	if (des.x >= 0 && des.x < game->max_x && des.y >= 0 && des.y < game->max_y)
	{
		if (game->map[des.y][des.x] != '1')
		{
			ft_printf("%d\n", ++game->player.moves);
			if (game->map[des.y][des.x] == 'C')
				game->player.collectibles++;
			else if (game->map[des.y][des.x] == 'E')
			{
				if (activate_ending(game) == -1)
					return ;
			}
			move_player(game, des);
		}
	}
	load_map(game, game->player.position);
}

static int	activate_ending(t_game *game)
{
	reload_images(game);
	if (get_element_position(game->map, 'C').x == -1)
	{
		game->scene_id = 21;
		game->scene = true;
		handle_scenes(game);
		return (1);
	}
	game->scene_id = 11;
	game->scene = true;
	handle_scenes(game);
	return (-1);
}

static void	move_player(t_game *game, t_position destiny)
{
	game->map[game->player.position.y][game->player.position.x] = '0';
	game->map[destiny.y][destiny.x] = 'P';
	game->player.position = destiny;
}

static t_position	calculate_destiny(t_position player_pos, t_head direction)
{
	if (direction == UP)
		return ((t_position){player_pos.x, player_pos.y - 1});
	else if (direction == DOWN)
		return ((t_position){player_pos.x, player_pos.y + 1});
	else if (direction == LEFT)
		return ((t_position){player_pos.x - 1, player_pos.y});
	else if (direction == RIGHT)
		return ((t_position){player_pos.x + 1, player_pos.y});
	return ((t_position){-1, -1});
}
