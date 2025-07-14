/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:45:42 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/09 16:06:40 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	res;

	if (nb <= 0)
	{
		return (0);
	}
	res = 1;
	while (res * res < nb)
	{
		res++;
	}
	if (res * res == nb)
	{
		return (res);
	}
	return (0);
}

/*
int	main(void)
{
	printf("100 -> %d\n", ft_sqrt(100));
	printf("-90 -> %d\n", ft_sqrt(-90));
	printf("90 -> %d\n", ft_sqrt(90));
}
*/