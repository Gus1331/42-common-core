/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 02:38:44 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 02:55:55 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i] && i < n) && (s1[i] || s2[i]))
	{
		i++;
	}
	if ((s1[i] || s2[i]))
	{
		if(i == n)
			i--;
		return (s1[i] - s2[i]);
	}
	return (0);
}
