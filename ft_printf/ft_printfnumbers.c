/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnumbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:33:26 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/06 19:40:57 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_integer(const int nbr);
int	print_unsig_int(const unsigned int nbr);

int	print_unsig_int(const unsigned int nbr)
{
	int		printed;

	printed = 1;
	if (nbr / 10 > 1)
	{
		printed += print_unsig_int(nbr / 10);
	}
	else
	{
		write(1, &("0123456789"[nbr]), 1);
	}
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
		i = nbr * -1;
	}
	while (i / 10 > 1)
	{
		i /= 10;
		printed++;
	}
	ft_putnbr_fd(nbr, 1);
	return (printed);
}
