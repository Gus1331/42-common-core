/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:53:05 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/23 15:25:56 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set);
static char	*validade_inputs(char const *s1, char const *set);
static char	*trim(char *res, char const *s1, char const *set);
static char	*allocate_response(size_t size);
static void	skip_a_char(int *char_allowed, int *skipped_chars);

static void	skip_a_char(int *char_allowed, int *skipped_chars)
{
	*char_allowed = 0;
	*skipped_chars += 1;
}

static char	*allocate_response(size_t size)
{
	char	*res;

	res = malloc((size) * sizeof (char));
	if (!res)
		return ((void *) 0);
	return (res);
}

static char	*validade_inputs(char const *s1, char const *set)
{
	if (!set && s1)
		return (ft_strdup(s1));
	return ((void *) 0);
}

static char	*trim(char *res, char const *s1, char const *set)
{
	int		i;
	int		j;
	int		skipped_chars;
	int		char_allowed;

	if (!res)
		return ((void *) 0);
	i = 0;
	skipped_chars = 0;
	while (((char *)s1)[i])
	{
		j = 0;
		char_allowed = 1;
		while (((char *)set)[j])
		{
			if (((char *) s1)[i] == ((char *) set)[j++])
				skip_a_char(&char_allowed, &skipped_chars);
		}
		if (char_allowed)
			res[i - skipped_chars] = s1[i];
		i++;
	}
	res[i - skipped_chars] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	res_diff;
	int	set_s;

	if (!s1 || !set)
		return (validade_inputs(s1, set));
	set_s = ft_strlen(set);
	res_diff = 0;
	i = 0;
	while (((char *)s1)[i])
	{
		j = 0;
		while (((char *)set)[j])
		{
			if (((char *) s1)[i] == ((char *) set)[j])
				res_diff++;
			j++;
		}
		i++;
	}
	return (trim(allocate_response(((size_t)i - res_diff + 1)), s1, set));
}
