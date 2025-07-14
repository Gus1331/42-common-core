/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:09:37 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/10 12:52:00 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);
void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	n1;

	n1 = '0';
	while (n1 != ('9' + 1))
	{
		ft_putchar(n1);
		n1++;
	}
}

/*
int	main()
{
	ft_print_numbers();
}
*/