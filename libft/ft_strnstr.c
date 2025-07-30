/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 03:26:16 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/30 14:41:31 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while ((size_t)i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j]
			&& big[i + j] && little[j]
			&& (size_t)i + j < len)
		{
			j++;
		}
		if (!little[j] || ((size_t)j == len && len != 0))
			return ((char *)&big[i]);
		i++;
	}
	return ((void *) 0);
}
