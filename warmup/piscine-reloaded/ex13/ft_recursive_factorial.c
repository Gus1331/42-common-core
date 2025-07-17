/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:05:37 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/17 14:04:39 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

/*
int	main(void)
{
	printf("0! = %d\n", ft_iterative_factorial(0));
	printf("1! = %d\n", ft_iterative_factorial(1));
	printf("3! = %d\n", ft_iterative_factorial(3));
	printf("5! = %d\n", ft_iterative_factorial(5));
}
*/