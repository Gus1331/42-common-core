/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 05:41:53 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 05:49:16 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while ((size_t)i < n)
	{
		*(int *)&s[i] = c;
		i++;
	}
	return (s);
}
