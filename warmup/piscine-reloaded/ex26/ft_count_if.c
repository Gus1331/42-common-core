/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:40:58 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/17 18:21:33 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*));

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;

	count = 0;
	while (*tab)
	{
		if (f(*tab) == 1)
		{
			count++;
		}
		tab++;
	}
	return (count);
}

/*
#include <stdio.h>
int	x(char *str){return str[0] == '\0' ? 1 : 2;}
int	main(void)
{
	
char *vec[] = {"a", "", "", "a", (void *) 0};
printf("%d", ft_count_if(vec, x));
}
*/
