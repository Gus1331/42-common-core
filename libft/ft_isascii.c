/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:03:02 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/21 01:47:48 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(char c);

int	ft_isascii(char c)
{	
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
