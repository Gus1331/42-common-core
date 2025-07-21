/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:25:11 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 16:49:53 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s || len == 0)
		return ((void *) 0);
	if (ft_strlen(s) <= start)
		return ((void *) 0);
	res = malloc(sizeof(char) *(len + 1));
	if (res == (void *)0)
		return ((void *)0);
	i = 0;
	while ((size_t)i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
