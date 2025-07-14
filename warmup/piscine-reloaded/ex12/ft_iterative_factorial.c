/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:05:37 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/09 15:44:45 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
	{
		return (0);
	}
	res = 1;
	while (nb > 1)
	{
		res *= nb--;
	}
	return (res);
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