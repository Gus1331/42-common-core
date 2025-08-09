/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:38:33 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/07 16:28:25 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(const unsigned long pointer_address);
int	print_base(const unsigned long nbr, char *base);

int	print_base(const unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i = print_base(nbr / 16, base);
	i += write(1, &base[nbr % 16], 1);
	return (i);
}

int	print_pointer(const unsigned long pointer_address)
{
	if (!pointer_address)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + print_base(pointer_address, "0123456789abcdef"));
}
