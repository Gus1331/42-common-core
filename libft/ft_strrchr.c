/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:13:26 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 01:48:40 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	while (ft_strchr(s, c) != (void *) 0)
	{
		last = (char *)s;
		s++;
	}
	if (last != (void *) 0)
		return (last);
	return ((void *) 0);
}
