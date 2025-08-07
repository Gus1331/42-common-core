/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:28:24 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/07 12:38:49 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(const int c);

int	print_char(const int c)
{
	if (c == 0)
		return (0);
	write(1, &c, 1);
	return (1);
}
