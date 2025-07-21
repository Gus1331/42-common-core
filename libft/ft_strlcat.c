/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:37:23 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 00:55:10 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size);

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	int	dst_len;
	int	i;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size <= (size_t)dst_len)
		return (size + ft_strlen(src));
	while (size - dst_len - 1 > (size_t)i && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
