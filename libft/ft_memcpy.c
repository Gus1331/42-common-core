/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 05:52:06 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 09:53:04 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*p_d;
	char	*p_s;

	p_d = (char *)dest;
	p_s = (char *)src;
	i = 0;
	while ((size_t)i < n)
	{
		p_d[i] = p_s[i];
		i++;
	}
	return (dest);
}
