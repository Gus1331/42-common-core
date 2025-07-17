/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:14:32 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/09 16:32:34 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str++)
	{
		n++;
	}
	return (n);
}

/*
int	main(void)
{
	char *string = "123456789";
	printf("%s -> %d", string, ft_strlen(string));
}
*/