/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:54:02 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/30 11:54:02 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char		*ft_itoa(int n);
static int	nbr_size(int nbr);
static int	ft_recursive_power(int nb, int power);
static char	*allocate_response_itoa(int *i, int *j, int *n);

static char	*allocate_response_itoa(int *i, int *j, int *n)
{
	char	*res;

	if (*n < 0)
	{
		*i = *i + 1;
		*j = *j + 1;
	}
	res = malloc((*i + 1) * sizeof(char));
	if (!res)
		return ((void *) 0);
	res[*i] = '\0';
	if (*n < 0)
	{
		res[0] = '-';
		*i = *i - 1;
		*n *= -1;
	}
	return (res);
}

int	ft_recursive_power(int nb, int power)
{
	if (power <= 1)
		return (nb);
	else if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

static int	nbr_size(int nbr)
{
	int	n_numbers_size;

	if (nbr < 0)
		nbr *= -1;
	n_numbers_size = 1;
	while (nbr >= 10)
	{
		n_numbers_size++;
		nbr = nbr / 10;
	}
	return (n_numbers_size);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*res;

	i = nbr_size(n);
	j = 0;
	res = allocate_response_itoa(&i, &j, &n);
	if (!res)
		return ((void *) 0);
	while (i > 0)
	{
		if (i > 1)
		{
			res[j++] = (n / (ft_recursive_power(10, i - 1))) + '0';
			n = n % (ft_recursive_power(10, i - 1));
		}
		else
			res[j++] = n + '0';
		i--;
	}
	return (res);
}
