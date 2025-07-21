/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:28:35 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/20 23:27:38 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, size_t size);

int	ft_strlcpy(char *dst, char *src, size_t size)
{
	int	src_s;
	int	i;

	i = 0;
	src_s = ft_strlen(src);
	while (src_s > i && (int)size - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_s);
	// while (i < src_s && i < (int)size - 1) {
    //     dst[i] = src[i];
    //     i++;
    // }
    // dst[i] = '\0';
    // return src_s;
}
