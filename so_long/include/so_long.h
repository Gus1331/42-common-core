/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 07:35:16 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/07 23:03:43 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include "MLX42/MLX42.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef enum e_head
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_head;

typedef struct s_texture
{
	mlx_texture_t	*background;
	mlx_texture_t	*water;
	mlx_texture_t	*wall;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	mlx_texture_t	*end;
	mlx_texture_t	*collectibles;
	mlx_texture_t	*item_icon;
}	t_texture;

typedef struct s_images
{
	mlx_image_t	*background;
	mlx_image_t	*water;
	mlx_image_t	*wall;
	mlx_image_t	*player_down;
	mlx_image_t	*player_up;
	mlx_image_t	*player_left;
	mlx_image_t	*player_right;
	mlx_image_t	*end;
	mlx_image_t	*collectibles;
	mlx_image_t	*item_icon;
}	t_images;

typedef struct s_player
{
	int			moves;
	t_position	position;
	int			collectibles;
	t_head		head;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	int			max_x;
	int			max_y;
	bool		scene;
	int			scene_id;
	t_player	player;
	t_texture	textures;
	t_images	images;
}	t_game;

/* Keys & Control */
void		key_hook(mlx_key_data_t keydata, void *mlx);

/* MAP */
char		**validate_map(char *map_name);
void		validate_map_playable(char **map);
void		validate_map_elements(char **map);
void		invalid_map(char *msg, char **map);
int			load_images(t_game *game);
void		reload_images(t_game *game);
void		load_map(t_game *game, t_position c_pos);
t_position	get_element_position(char **map, char element);

/* Events */
void		game_error(char *msg, t_game game);
t_game		game_init(char **map);
void		close_game(t_game game);
void		move(t_game *game, t_head direction);
void		scene(t_game game, char *file_path);
void		handle_scenes(t_game *game);

/* Player */
t_player	init_player(t_game game);
void		add_collectible(t_player *player);

/* Textures */
void		load_textures(t_game *game);
void		unload_textures(t_texture textures);

#endif
