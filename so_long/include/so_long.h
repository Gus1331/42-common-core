/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 07:35:16 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/25 08:13:57 by gustaoli         ###   ########.fr       */
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

/* Keys & Control */
void	key_hook(mlx_key_data_t keydata, void *mlx);

/* MAP */
char	**validate_map(char *map_name);
void	validate_map_playable(char **map);
void	validate_map_elements(char **map);
void	invalid_map(char *msg, char **map);


#endif
