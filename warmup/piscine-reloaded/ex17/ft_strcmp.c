/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:50:30 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/09 17:13:16 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 || *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 || *s2)
	{
		return (*s1 - *s2);
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_strcmp("Lorem", "Lorem"));
	printf("%d\n", ft_strcmp("Lorem b", "Lorem a"));
	printf("%d\n", ft_strcmp("Lorem Ipzum", "Lorem Ipsum"));
}
*/