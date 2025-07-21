/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:42:03 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 00:56:17 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	printf("%d", (int)c);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
