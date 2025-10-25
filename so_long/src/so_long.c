/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 07:35:30 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/25 09:52:54 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	mlx_t	*mlx;

	if (argc != 2)
		exit(EXIT_FAILURE);
	ft_free_str_arr(validate_map(argv[1]));
	mlx = mlx_init(1200, 900, "Half Piece 🏴‍☠️", true);
	if (!mlx)
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
