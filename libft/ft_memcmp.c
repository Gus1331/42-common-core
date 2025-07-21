/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 04:53:03 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 05:38:48 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > (size_t)i)
	{
		if (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i] != 0)
			return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
		i++;
	}
	return (0);
}
