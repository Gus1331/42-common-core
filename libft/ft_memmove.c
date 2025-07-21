/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 06:30:13 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 06:39:37 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	aux[n];
	char	*p_d;
	char	*p_s;

	i = 0;
	p_d = (char *)dest;
	p_s = (char *)src;
	while ((size_t)i < n)
	{
		aux[i] = p_s[i];
		i++;
	}
	i = 0;
	while ((size_t)i < n)
	{
		p_d[i] = aux[i];
		i++;
	}
	return (dest);
}
