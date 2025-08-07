/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:38:33 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/07 12:38:39 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_hex(const unsigned int nbr, char format);
int			print_pointer(const long pointer_address);
static char	*long_to_hex(const unsigned int nbr);

int	print_hex(const unsigned int nbr, char format)
{
	int		printed;
	char	*hex;

	hex = long_to_hex(nbr);
	if (format == 'X')
	{
		while (*hex)
		{
			if (ft_isalpha(*hex))
				*hex = ft_toupper(*hex);
			hex++;
		}
	}
	printed = ft_strlen(hex);
	free(hex);
	return (printed);
}

static char	*long_to_hex(const unsigned int nbr)
{
	char			*res;
	unsigned int	n;
	int				i;

	i = 0;
	res = malloc(13 * sizeof(char));
	res[12] = '\0';
	n = nbr;
	while (n >= 16)
	{
		res[11 - i++] = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
	res[0] = "0123456789abcdef"[n];
	return (res);
}

int	print_pointer(const long pointer_address)
{
	int		printed;
	char	*pointer_hex;

	if (!pointer_address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	pointer_hex = long_to_hex((const unsigned long)pointer_address);
	ft_putstr_fd(pointer_hex, 1);
	printed = 2 + ft_strlen(pointer_hex);
	free(pointer_hex);
	return (printed);
}
