/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:09:54 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 09:19:54 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	char	*res;
	int		s_s;

	s_s = 0;
	if (s == ((void *) 0))
	{
		return ((void *) 0);
	}
	else if (!(*s == '\0'))
	{
		s_s = ft_strlen(s);
	}
	res = ft_calloc((s_s + 1), sizeof (char));
	ft_memcpy(res, s, s_s + 1);
	return (res);
}
