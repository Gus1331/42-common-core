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
static int	handle_format(char format, va_list args);

static int	handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(va_arg(args, int)));
	else if (format == 's')
		return (print_string(va_arg(args, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(args, long)));
	else if (format == 'd' || format == 'i')
		return (print_integer(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsig_int(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (print_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (print_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (print_char('%'));
	return (0);
}

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
				print_count += handle_format(*format, args);
		}
		else
			print_count += write(1, &*format, 1);
		format++;
	}
	va_end(args);
	return (print_count);
}
