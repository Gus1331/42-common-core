/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:27 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/25 16:00:50 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);
int		word_count(char const *s, char c);
int		find_next_delimiter(char const *s, int start, char c);

int	find_next_delimiter(char const *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start + i])
	{
		if (s[start + i] == c)
			return (start + i);
		i++;
	}
	return (start);
}

int	word_count(char const *s, char c)
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
	int		next_delimeter;
	int		w_count;
	int		i;
	//int		j;

	if (!s)
		return ((void *) 0);
	if (c == '\0')
		w_count = 1;
	else
		w_count = word_count(s, c);
	printf("\nword count = %d;", w_count);
	i = 0;
	res = malloc(w_count * sizeof(char *));
	if (!res)
		return ((void *) 0);
	while (w_count > 0)
	{
		next_delimeter = find_next_delimiter(s, i, c);
		printf("\nnext delimiter = %d;", next_delimeter);
		printf("\n>>");
		while (i <= next_delimeter)
		{
			printf("o");
			i++;
		}
		printf("<<\n");
		w_count--;
	}
	return ((void *) 0);
}

/*
"abc-def-ghi-"
*/