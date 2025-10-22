/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:43:28 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/21 21:28:24 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		validate_cmds(int argc, char **argv, char **envv);
void		free_paths(char **paths);
char		**get_bin_paths(char **envv);
static char	**format_bin_paths(char *path_env);

void	validate_cmds(int argc, char **argv, char **envv)
{
	char	**bin_paths;
	char	*aux;
	int		i;

	bin_paths = get_bin_paths(envv);
	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		i = 3;
	}
	while (i < argc - 1)
	{
		aux = verify_cmd_in_bin_paths(argv[i], bin_paths);
		if (aux == NULL)
		{
			ft_printf("Command not found: %s\n", argv[i]);
			free_paths(bin_paths);
			exit(EXIT_FAILURE);
		}
		free(aux);
		i++;
	}
	free_paths(bin_paths);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		here_doc(argc, argv, envv);
}

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
