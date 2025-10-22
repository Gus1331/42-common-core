/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_white_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:18:31 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/11 10:31:14 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This group not quoted white spaces accepted in bash
and replace for ' ' them in a new str
(also trim edges)
Example:
	in:  '  \t\tcmd  "inquote \t\t str \r" \t'
	out: 'cmd "inquote \t\t str \r"'
*/

#include "libft.h"

char		*ft_group_white_spaces(char *str);
static void	copy_quotes(char *dst, int *dst_size, char **src);
static void	skip_spaces(char **str);

char	*ft_group_white_spaces(char *str)
{
	char	*res;
	int		i;

	res = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\r')
		{
			skip_spaces(&str);
			if (i > 0 && *str)
				res[i++] = ' ';
		}
		else if (*str == '\'' || *str == '\"')
			copy_quotes(res, &i, &str);
		else
		{
			res[i++] = *str;
			str++;
		}
	}
	return (res);
}

static void	copy_quotes(char *dst, int *dst_size, char **src)
{
	char	quote_type;

	if (*(*src) != '\'' && *(*src) != '\"')
		return ;
	quote_type = *(*src);
	dst[(*dst_size)++] = *(*src);
	(*src)++;
	while (*(*src) && *(*src) != quote_type)
	{
		dst[(*dst_size)++] = *(*src);
		(*src)++;
	}
	if (**src == quote_type)
	{
		dst[(*dst_size)++] = **src;
		(*src)++;
	}
}

static void	skip_spaces(char **str)
{
	while (**str == ' '
		|| **str == '\t'
		|| **str == '\r')
		(*str)++;
}
