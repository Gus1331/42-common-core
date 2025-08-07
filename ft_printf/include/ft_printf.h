/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:04:43 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/07 12:21:21 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	print_char(const int c);
int	print_integer(const int nbr);
int	print_string(const char *str);
int	print_unsig_int(const unsigned int nbr);
int	print_pointer(const long pointer_address);
int	print_hex(const unsigned int nbr, char format);

int	ft_printf(const char *format, ...);

#endif