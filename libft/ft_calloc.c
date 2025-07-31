/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 07:06:06 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/30 19:16:07 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb == 0 || size == 0)
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		return (res);
	}
	res = malloc(nmemb * size);
	if (!res)
		return ((void *) 0);
	ft_memset(res, 0, nmemb * size);
	return (res);
}
