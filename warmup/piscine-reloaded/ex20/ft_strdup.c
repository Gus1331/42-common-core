/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:59:18 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/10 13:14:47 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i++])
	res = malloc(i * sizeof(char));
	i = 0;
	while (*src)
		res[i++] = *src++;
	res[i] = '\0';
	return (res);
}

/*
int	main(void)
{
	char	*str;

	str = ft_strdup("Lorem Ipsum Dolor Sit.");
	printf("%s", str);
}
*/
