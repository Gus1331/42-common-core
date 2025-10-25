/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 06:40:50 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/25 07:12:14 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_arr(char **str_array);

void	ft_free_str_arr(char **str_array)
{
	char	**aux;

	aux = str_array;
	while (*aux != NULL)
	{
		free(*aux);
		aux++;
	}
	free(str_array);
}
