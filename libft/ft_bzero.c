/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 03:08:58 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 03:24:38 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	int	i;
	int	*p_s;

	i = 0;
	while ((size_t)i < n)
	{
		p_s = (int *)s;
		*p_s = 0;
		i++;
		s++;
	}
}
