/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:17:07 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/10 14:38:24 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	i = 0;
	while ((min + i) < max)
		i++;
	res = malloc(i * sizeof(int));
	if (min >= max)
		return (res);
	i = 0;
	while (min < max)
	{
		res[i++] = min++;
	}
	return (res);
}

/*
//printf("s = %d\n", i); 
//printf("arr[%d] = %d\n", i-1, min-1);
int	main(void)
{
	int	*arr;
	arr = ft_range(10, 20);
	printf("[%d, %d... %d]", arr[0], arr[1], arr[9]);
}
*/
