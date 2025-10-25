/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 07:34:29 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/25 08:00:35 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_arr_dup(char **str_array);

char	**ft_str_arr_dup(char **str_array)
{
	char	**duplicate;
	int		count;
	int		i;

	count = 0;
	while (str_array[count])
		count++;
	duplicate = malloc((count + 1) * sizeof(char *));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (str_array[i])
	{
		duplicate[i] = ft_strdup(str_array[i]);
		i++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}
