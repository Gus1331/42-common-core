/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:38:33 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/06 20:58:37 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			print_hex(const unsigned int nbr, char format);
int			print_pointer(const long pointer_address);
static char	*long_to_hex(const unsigned long nbr);

int	print_hex(const unsigned int nbr, char format)
{
	int		printed;
	char	*hex;
	char	*aux;

	hex = long_to_hex((unsigned long)nbr);
	if (format == 'X')
	{
		aux = ft_strmapi(hex, (char (*)(unsigned int, char ))ft_toupper);
		ft_putstr_fd(aux, 1);
		free(aux);
	}
	else
		ft_putstr_fd(hex, 1);
	printed = ft_strlen(hex);
	free(hex);
	return (printed);
}

static char	*long_to_hex(const unsigned long nbr)
{
	char			*res;
	unsigned long	n;
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
