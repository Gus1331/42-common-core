/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:22:58 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/20 22:17:49 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(char c);

int	ft_isprint(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
