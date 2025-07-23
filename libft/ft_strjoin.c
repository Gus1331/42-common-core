/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:52:04 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/23 10:50:50 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		s1_s;
	int		s2_s;
	int		i;

	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	if (s1 == (void *) 0 || s2 == (void *) 0)
		return ((void *) 0);
	res = malloc((s1_s + s2_s + 1) * sizeof(const char));
	if (res == (void *) 0)
		return ((void *) 0);
	i = 0;
	while (i < s1_s + s2_s)
	{
		if (s1_s > i)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1_s];
		i++;
	}
	res[s1_s + s2_s] = '\0';
	return (res);
}
