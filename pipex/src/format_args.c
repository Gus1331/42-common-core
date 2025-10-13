/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:12:11 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/13 07:03:11 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char		**get_args(char *cmd);
static char	*get_next_arg(char **str);
static void	skip_spaces(char **str);
static void	clean_args_quotes(char **args);

char	**get_args(char *cmd)
{
	int		size;
	char	**args;

	args = NULL;
	size = 0;
	if (!*cmd)
	{
		args = malloc(sizeof(char *));
		*args = NULL;
		return (args);
	}
	skip_spaces(&cmd);
	while (*cmd)
	{
		args = ft_realloc(args, size * sizeof(char *),
				(size + 1) * sizeof(char *));
		args[size] = get_next_arg(&cmd);
		size++;
		skip_spaces(&cmd);
	}
	args = ft_realloc(args, size * sizeof(char *), (size + 1) * sizeof(char *));
	args[size] = NULL;
	clean_args_quotes(args);
	return (args);
}

static char	*get_next_arg(char **str)
{
	char	*start;
	char	*end;
	char	quote;

	skip_spaces(str);
	start = *str;
	end = *str;
	quote = 0;
	while (*end && (quote || *end != ' '))
	{
		if (!quote && (*end == '\'' || *end == '\"'))
		{
			quote = *end;
			end++;
			while (*end && *end != quote)
				end++;
			if (*end == quote)
				end++;
			quote = 0;
		}
		else
			end++;
	}
	*str = end;
	return (ft_substr(start, 0, end - start));
}

static void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

static void	clean_args_quotes(char **args)
{
	int		i;
	char	*aux;

	i = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], '\''))
		{
			aux = args[i];
			args[i] = ft_replace(args[i], "\'", "");
			free(aux);
		}
		if (ft_strchr(args[i], '\"'))
		{
			aux = args[i];
			args[i] = ft_replace(args[i], "\"", "");
			free(aux);
		}
		i++;
	}
}
