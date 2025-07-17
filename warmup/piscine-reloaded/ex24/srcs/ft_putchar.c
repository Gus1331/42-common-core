/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:20:28 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/17 10:10:40 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mylib.h>

void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
int	main()
{
	char c;

	c	= '4';
	ft_putchar(c);	
}
*/