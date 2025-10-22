/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:32:20 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/21 21:32:59 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int			here_doc(int argc, char *argv[], char *envv[]);
static void	put_here_doc_in_pipe(char *delimiter, int pipefd[2]);
static void	last_command(char *file, char *cmd, char *envv[], int pipefd[2]);
static char	*get_here_doc_content(char *delimiter);

int	here_doc(int argc, char *argv[], char *envv[])
{
	int		pipe_prev[2];
	int		pipe_next[2];
	pid_t	pid;

	if (argc < 6)
		exit(EXIT_FAILURE);
	if (pipe(pipe_next) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		put_here_doc_in_pipe(argv[2], pipe_next);
	close(pipe_next[1]);
	pipe_prev[0] = pipe_next[0];
	run_mid_commands(argv, envv, pipe_prev, pipe_next);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		last_command(argv[argc - 1], argv[argc - 2], envv, pipe_prev);
	close(pipe_prev[0]);
	wait_child();
	exit(EXIT_SUCCESS);
}

static void	put_here_doc_in_pipe(char *delimiter, int pipefd[2])
{
	char	*content;

	content = get_here_doc_content(delimiter);
	close(pipefd[0]);
	write(pipefd[1], content, ft_strlen(content));
	close(pipefd[1]);
	free(content);
	exit(EXIT_SUCCESS);
}

static void	last_command(char *file, char *cmd, char *envv[], int pipefd[2])
{
	int	fd_out;

	fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_out == -1)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	if (!*cmd)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipefd[0]);
	execute_command(cmd, envv);
}

static char	*get_here_doc_content(char *delimiter)
{
	char	*content;
	char	*buff;
	char	*aux;
	int		delimiter_size;

	delimiter_size = ft_strlen(delimiter);
	content = ft_strdup("");
	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		if (ft_strncmp(buff, delimiter, delimiter_size) == 0
			&& (buff[delimiter_size] == '\n' || buff[delimiter_size] == '\0'))
			break ;
		aux = ft_strjoin(content, buff);
		free(content);
		content = aux;
		free(buff);
	}
	free(buff);
	get_next_line(-1);
	return (content);
}
