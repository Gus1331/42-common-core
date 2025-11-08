/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 04:38:25 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/05 23:53:04 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		validate_map_elements(char **map);
void		validate_map_playable(char **map);
t_position	get_element_position(char **map, char element);
static void	fill(char **map, t_position pos);

void	validate_map_elements(char **map)
{
	int	c_p_e_count[3];
	int	x;
	int	y;

	c_p_e_count[0] = 0;
	c_p_e_count[1] = 0;
	c_p_e_count[2] = 0;
	x = 0;
	while (map[++x])
	{
		y = 0;
		while (map[x][++y])
		{
			if (map[x][y] == 'C')
				c_p_e_count[0]++;
			else if (map[x][y] == 'P')
				c_p_e_count[1]++;
			else if (map[x][y] == 'E')
				c_p_e_count[2]++;
			else if (map[x][y] != '0' && map[x][y] != '1')
				invalid_map("Unkown element present!", map);
		}
	}
	if (c_p_e_count[0] < 1 || c_p_e_count[1] != 1 || c_p_e_count[2] != 1)
		invalid_map("Too much or too less 'P','C' or 'E' elements!", map);
}

void	validate_map_playable(char **map)
{
	char		**map_dup;
	t_position	end;

	map_dup = ft_str_arr_dup(map);
	if (!map_dup)
	{
		ft_printf("Malloc Error!");
		ft_free_str_arr(map);
		exit(EXIT_FAILURE);
	}
	fill(map_dup, get_element_position(map, 'P'));
	end = get_element_position(map, 'E');
	if (map_dup[end.y][end.x - 1] != '@' && map_dup[end.y][end.x + 1] != '@'
		&& map_dup[end.y - 1][end.x] != '@'
		&& map_dup[end.y + 1][end.x] != '@')
	{
		ft_free_str_arr(map_dup);
		invalid_map("End is not reacheable!", map);
	}
	if (get_element_position(map_dup, 'C').x != -1)
	{
		ft_free_str_arr(map_dup);
		invalid_map("There is a collectible that is not reacheable!", map);
	}
	ft_free_str_arr(map_dup);
}

t_position	get_element_position(char **map, char element)
{
	int	line;
	int	column;

	line = 1;
	while (map[line])
	{
		column = 1;
		while (map[line][column])
		{
			if (map[line][column] == element)
				return ((t_position){column, line});
			column++;
		}
		line++;
	}
	return ((t_position){-1, -1});
}

static void	fill(char **map, t_position pos)
{
	if (map[pos.y][pos.x] != '0' && map[pos.y][pos.x] != 'C'
			&& map[pos.y][pos.x] != 'P')
		return ;
	map[pos.y][pos.x] = '@';
	fill(map, (t_position){pos.x - 1, pos.y});
	fill(map, (t_position){pos.x, pos.y - 1});
	fill(map, (t_position){pos.x + 1, pos.y});
	fill(map, (t_position){pos.x, pos.y + 1});
}
