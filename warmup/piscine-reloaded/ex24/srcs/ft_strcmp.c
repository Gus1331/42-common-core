/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:57:43 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/15 11:39:27 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);
int	ft_charcmp(char c1, char c2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	cmp;

	i = 0;
	while (s1[i] || s2[i])
	{
		cmp = ft_charcmp(s1[i], s2[i]);
		if (cmp != 0)
		{
			return (cmp);
		}
		i++;
	}
	return (0);
}

int	ft_charcmp(char c1, char c2)
{
	return (c1 - c2);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("0 - %i\n", ft_strcmp("A","B"));
	printf("1 - %i\n", ft_strcmp("4","2"));
	printf("2 - %i\n", ft_strcmp("2","2"));
	printf("3 - %i\n", ft_strcmp("4242","2424"));
	printf("4 - %i\n", ft_strcmp("424242","4242"));
}
*/