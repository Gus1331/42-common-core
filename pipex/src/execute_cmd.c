/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:41:37 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/15 01:21:50 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		execute_command(char *cmd, char *envv[]);
char		*verify_cmd_in_bin_paths(char *cmd, char **bin_paths);
void		wait_child(void);
static char	*construct_path(char *bin_path, char *cmd);

void	execute_command(char *cmd, char *envv[])
{
	char	**paths;
	char	*full_path;
	char	**args;

	paths = get_bin_paths(envv);
	full_path = verify_cmd_in_bin_paths(cmd, paths);
	args = get_args(cmd);
	if (!full_path)
	{
		ft_printf("Command not found: %s\n", cmd);
		free_paths(paths);
		free_paths(args);
		exit(EXIT_FAILURE);
	}
	execve(full_path, args, envv);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

char	*verify_cmd_in_bin_paths(char *cmd, char **bin_paths)
{
	char	*full_bin_path;

	while (*bin_paths != NULL)
	{
		full_bin_path = construct_path(*bin_paths, cmd);
		if (access(full_bin_path, X_OK) == 0)
			return (full_bin_path);
		bin_paths++;
		free(full_bin_path);
	}
	return (NULL);
}

void	wait_child(void)
{
	while (wait(NULL) > 0)
		;
}

static char	*construct_path(char *bin_path, char *cmd)
{
	char	*res;
	char	*aux;
	char	*cmd_end_p;

	cmd_end_p = ft_strchr(cmd, ' ');
	if (cmd_end_p == NULL)
		cmd_end_p = cmd + ft_strlen(cmd);
	res = ft_calloc(ft_strlen(bin_path)
			+ (cmd_end_p - cmd) + 1, sizeof(char));
	ft_strlcat(res, bin_path, ft_strlen(bin_path) + 1);
	aux = res + ft_strlen(res);
	if (*aux != '/')
		ft_strlcat(aux, "/", 2);
	aux = res + ft_strlen(res);
	ft_strlcat(aux, cmd, (cmd_end_p - cmd) + 1);
	return (res);
}
