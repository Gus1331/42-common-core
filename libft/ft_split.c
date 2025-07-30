/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:27 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/30 11:44:36 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
static int	word_count(char const *s, char c);
static void	free_res(char **res);

static void	free_res(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	word_count(char const *s, char c)
{
	int	w_count;
	int	start;
	int	i;

	start = 0;
	w_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i > start)
		{
			w_count++;
			start = i + 1;
		}
		else if (s[i] == c)
		{
			start++;
		}
		i++;
	}
	if (i > start)
		w_count++;
	return (w_count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		w_count;
	int		i;
	int		start;
	int		end;

	w_count = word_count(s, c);
	res = malloc((w_count + 1) * sizeof(char *));
	if (!res)
		return ((void *) 0);
	i = 0;
	end = 0;
	start = 0;
	while (i < w_count)
	{
		while (s[start] == c)
			end = ++start;
		while (s[end] && s[end] != c)
			end++;
		res[i] = ft_substr(s, start, end - start);
		if (!res[i++])
			free_res(res);
		start = end;
	}
	return (res[i] = ((void *) 0), res);
}
