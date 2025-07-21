/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 04:08:31 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 04:50:22 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*p_s;

	i = 0;
	p_s = (char *) s;
	while (n > (size_t)i)
	{
		if (p_s[i] == (char)c)
			return ((void *)&p_s[i]);
		i++;
	}
	return ((void *) 0);
}
