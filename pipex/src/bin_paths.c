/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:43:28 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/13 02:13:22 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		free_paths(char **paths);
char		**get_bin_paths(char **envv);
static char	**format_bin_paths(char *path_env);

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
		free(paths[i++]);
	free(paths);
}

char	**get_bin_paths(char **envv)
{
	while (*envv != NULL)
	{
		if (ft_strncmp(*envv, "PATH=", 5) == 0)
			break ;
		envv++;
	}
	return (format_bin_paths(*envv + 5));
}

static char	**format_bin_paths(char *path_env)
{
	char	**res;

	res = ft_split(path_env, ':');
	if (!res)
		exit(EXIT_FAILURE);
	return (res);
}
