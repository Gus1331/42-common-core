/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:50:27 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/25 06:51:15 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(char *msg, char **map);

void	invalid_map(char *msg, char **map)
{
	ft_printf("Invalid map! %s\n", msg);
	if (map)
		ft_free_str_arr(map);
	exit(EXIT_FAILURE);
}
