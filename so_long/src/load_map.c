/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:42:16 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/06 00:50:09 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void				load_map(t_game *game, t_position c_pos);
static void			load_background(t_game *game);
static void			load_elements(t_game *game, t_position c_pos);
static void			put_image(t_game *game, t_position pos, mlx_image_t *img);
static mlx_image_t	*select_image(t_game *game, t_position img_pos);

void	load_map(t_game *game, t_position c_pos)
{
	if (game->scene == true)
		return ;
	reload_images(game);
	load_background(game);
	load_elements(game, c_pos);
	if (get_element_position(game->map, 'C').y == -1)
		mlx_image_to_window(game->mlx, game->images.item_icon, 2, 826);
	if (game->player.head == DOWN)
		mlx_image_to_window(game->mlx, game->images.player_down, 512, 384);
	if (game->player.head == UP)
		mlx_image_to_window(game->mlx, game->images.player_up, 512, 384);
	if (game->player.head == LEFT)
		mlx_image_to_window(game->mlx, game->images.player_left, 512, 384);
	if (game->player.head == RIGHT)
		mlx_image_to_window(game->mlx, game->images.player_right, 512, 384);
}

static void	load_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 7)
			mlx_image_to_window(game->mlx,
				game->images.water, x * 128, (y++) * 128);
		x++;
	}
}

static void	load_elements(t_game *game, t_position c_pos)
{
	int	x;
	int	x_it;
	int	y;
	int	y_it;

	x = c_pos.x - 4;
	x_it = 0;
	while (x_it < 9)
	{
		y = c_pos.y - 3;
		y_it = 0;
		while (y_it <= 6)
		{
			if (x >= 0 && x < game->max_x && y >= 0
				&& y < game->max_y && x < game->max_x)
				put_image(game, (t_position){x_it, y_it},
					select_image(game, (t_position){x, y}));
			y_it++;
			y++;
		}
		x++;
		x_it++;
	}
}

static void	put_image(t_game *game, t_position pos, mlx_image_t *img)
{
	int	x;
	int	y;

	if (pos.x < 0 || pos.y < 0
		|| pos.x > game->max_x + 2 || pos.y > game->max_y + 1)
	{
		ft_printf("invalid pos x=%d, y=%d\n", pos.x, pos.y);
		game_error("Invalid image position", *game);
	}
	if (!img)
		return ;
	x = pos.x * 128;
	y = pos.y * 128;
	mlx_image_to_window(game->mlx, img, x, y);
}

static mlx_image_t	*select_image(t_game *game, t_position img_pos)
{
	if (game->map[img_pos.y][img_pos.x] == '1')
		return (game->images.wall);
	else if (game->map[img_pos.y][img_pos.x] == 'C')
		return (game->images.collectibles);
	else if (game->map[img_pos.y][img_pos.x] == 'E')
		return (game->images.end);
	return (NULL);
}
