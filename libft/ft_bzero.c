/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 03:08:58 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/30 13:20:45 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*p_s;

	i = 0;
	p_s = (char *)s;
	while ((size_t)i < n)
	{
		p_s[i] = 0;
		i++;
	}
}
