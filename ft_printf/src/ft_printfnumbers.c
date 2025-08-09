/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:33:26 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/07 16:41:19 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(const int nbr);
int	print_unsig_int(const unsigned int nbr);

int	print_unsig_int(const unsigned int nbr)
{
	int		printed;

	printed = 0;
	if (nbr >= 10)
		printed += print_unsig_int(nbr / 10);
	printed += write(1, &("0123456789"[nbr % 10]), 1);
	return (printed);
}

int	print_integer(const int nbr)
{
	int		printed;
	long	i;

	i = nbr;
	printed = 1;
	if (nbr < 0)
	{
		printed++;
		write (1, "-", 1);
		i = i * -1;
	}
	if (i >= 10)
		printed += print_integer(i / 10);
	ft_putnbr_fd(i % 10, 1);
	return (printed);
}
