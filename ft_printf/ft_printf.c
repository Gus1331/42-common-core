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

#include "libft.h"
#include <stdarg.h>

int			ft_printf(const char *format, ...);
extern int	print_char(const int c);
extern int	print_string(const char *str);
extern int	print_pointer(const long pointer_address);
extern int	print_integer(const int nbr);
extern int	print_unsig_int(const unsigned int nbr);
extern int	print_hex(const int nbr, char format);

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

#include <stdio.h>
int	main(void)
{
	int *a;
	int	b;

	b = 1;
	a = &b;
	ft_putnbr_fd(ft_printf("\nHello Word!\n%x\n", -42), 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(printf("\nHello Word>\n%x\n", -42), 1);
	return (0);
}
