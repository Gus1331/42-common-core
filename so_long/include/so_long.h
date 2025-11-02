/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 07:35:16 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/02 05:42:04 by gustaoli         ###   ########.fr       */
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
}	t_images;

typedef struct s_player
{
	t_position	position;
	int			collectibles;
}	t_player;


typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	int			max_x;
	int			max_y;
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
void		load_map(t_game *game, t_position c_pos);
t_position	get_element_position(char **map, char element);

/* Events */
void		game_error(char *msg, t_game game);
t_game		game_init(char **map);
void		close_game(t_game game);

/* Textures */
void		load_textures(t_game *game);
void		unload_textures(t_texture textures);

#endif
