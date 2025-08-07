/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:27:11 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/06 11:27:11 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_count;

	va_start(args, format);
	print_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_strchr("cspdiuxX\%", *++format) != NULL && *format != '\0')
			{
				if (*format == 'c')
					print_count += print_char(va_arg(args, int));
				else if (*format == 's')
					print_count += print_string(va_arg(args, char *));
				else if (*format == 'p')
					print_count += print_pointer(va_arg(args, long));
				else if (*format == 'd' || *format == 'i')
					print_count += print_integer(va_arg(args, int));
				else if (*format == 'u')
					print_count += print_unsig_int(va_arg(args, unsigned int));
				else if (*format == 'x' || *format == 'X')
					print_count += print_hex(va_arg(args, unsigned int), *format);
			}
		}
		else
		{
			write(1, &*format, 1);
			print_count++;
		}
		format++;
	}
	return (print_count);
}

