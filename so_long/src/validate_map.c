/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 01:26:48 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/02 06:14:58 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char		**validate_map(char *map_name);
static char	**get_ber_content(int map);
static void	validate_edges(char **map);
//static void	print_map(char **map); // test ======================================

char	**validate_map(char *map_name)
{
	int		map_fd;
	char	**map;

	if (map_name == NULL || *map_name == '\0')
		invalid_map("No file name!", NULL);
	if (ft_strncmp(ft_strrchr(map_name, '.'), ".ber", 5) != 0)
		invalid_map("Invalid .ber file!", NULL);
	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
		invalid_map("Could not open the file!", NULL);
	map = get_ber_content(map_fd);
	close(map_fd);
	validate_edges(map);
	validate_map_elements(map);
	validate_map_playable(map);
	return (map);
}

static char	**get_ber_content(int map)
{
	char	**map_content;
	char	*aux;
	int		i;

	map_content = malloc(1 * sizeof(char *));
	if (!map_content)
		exit(EXIT_FAILURE);
	aux = get_next_line(map);
	i = 0;
	while (aux != NULL && *aux)
	{
		map_content = ft_realloc(map_content,
				(i + 1) * sizeof(char *), (i + 2) * sizeof(char *));
		if (!map_content)
			exit(EXIT_FAILURE);
		map_content[i] = ft_replace(aux, "\n", "");
		free(aux);
		aux = get_next_line(map);
		i++;
	}
	map_content[i] = NULL;
	return (close(map), (map_content));
}

static void	validate_edges(char **map)
{
	int	map_x_size;
	int	line;
	int	j;

	map_x_size = ft_strlen(*map);
	line = -1;
	while (map[++line])
	{
		if ((int)ft_strlen(map[line]) != map_x_size)
			invalid_map("Map are not a retangle!", map);
		if (line == 0 || map[line + 1] == NULL)
		{
			j = 0;
			while (map[line][j])
			{
				if (map[line][j++] != '1')
					invalid_map("Map edge not valid!", map);
			}
		}
		else
		{
			if (map[line][0] != '1' || map[line][map_x_size - 1] != '1')
				invalid_map("Map edge not valid!", map);
		}
	}
}
/*
static void	print_map(char **map) // para teste, não subir ===============================
{
	int i = 0; //
	ft_printf("\nMAP:\n{\n");
	while (map[i] != NULL && map[i][0]){ 
		int j = 0;
		while (map[i][j] != '\n' && map[i][j]) //
			ft_printf("%c ", map[i][j++]); //
		ft_printf("\n"); //condition
		i++; //
	} //
	ft_printf("}\n"); //
} // teste
 */
