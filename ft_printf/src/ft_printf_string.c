/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:30:40 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/07 16:25:56 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(const char *str);

int	print_string(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd((char *)str, 1);
	return (ft_strlen(str));
}
