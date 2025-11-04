/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 06:41:25 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/03 23:06:02 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player			init_player(t_game game);
void				add_collectible(t_player *player);
void				move(t_game *game, t_head direction);
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

void	add_collectible(t_player *player)
{
	player->collectibles++;
}

void	move(t_game *game, t_head direction)
{
	t_position	destiny;

	if (game->player.head != direction)
	{
		game->player.head = direction;
		load_map(game, game->player.position);
		return ;
	}
	destiny = calculate_destiny(game->player.position, direction);
	if (destiny.x >= 0 && destiny.x < game->max_x
		&& destiny.y >= 0 && destiny.y < game->max_y)
	{
		if (game->map[destiny.y][destiny.x] != '1')
		{
			ft_printf("%d\n", ++game->player.moves);
			if (game->map[destiny.y][destiny.x] == 'C')
				add_collectible(&game->player);
			else if (game->map[destiny.y][destiny.x] == 'E')
				close_game(*game);
			game->map[game->player.position.y][game->player.position.x] = '0';
			game->map[destiny.y][destiny.x] = 'P';
			game->player.position = destiny;
		}
	}
	load_map(game, game->player.position);
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
