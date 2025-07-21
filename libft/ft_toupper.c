/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:42:03 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 00:53:25 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int c);

int	ft_toupper(int c)
{
	printf("%d", (int)c);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
