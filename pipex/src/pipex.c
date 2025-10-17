/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:28:48 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/17 02:51:59 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		run_mid_commands(char *argv[], char *envv[],
				int prev_pipe[2], int next_pipe[2]);
static void	first_command(char *file, char *cmd, char *envv[], int pipefd[2]);
static void	last_command(char *file, char *cmd, char *envv[], int pipefd[2]);
static void	middle_command(char *cmd, char *envv[],
				int prev_pipe[2], int next_pipe[2]);

int	main(int argc, char *argv[], char *envv[])
{
	int		pipe_prev[2];
	int		pipe_next[2];
	pid_t	pid;

	if (argc < 5)
		return (1);
	validate_cmds(argc, argv, envv);
	if (pipe(pipe_next) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		first_command(argv[1], argv[2], envv, pipe_next);
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
	return (0);
}

void	run_mid_commands(char *argv[], char *envv[],
				int prev_pipe[2], int next_pipe[2])
{
	int		i;
	pid_t	pid;
	int		argc;

	i = 3;
	argc = 0;
	while (argv[argc])
		argc++;
	while (i < argc - 2)
	{
		if (!argv[i][0])
			exit(EXIT_FAILURE);
		if (pipe(next_pipe) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			middle_command(argv[i], envv, prev_pipe, next_pipe);
		close(prev_pipe[0]);
		close(next_pipe[1]);
		prev_pipe[0] = next_pipe[0];
		i++;
	}
}

static void	first_command(char *file, char *cmd, char *envv[], int pipefd[2])
{
	int	fd_in;

	fd_in = open(file, O_RDONLY);
	if (fd_in == -1)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	if (!*cmd)
		exit(EXIT_FAILURE);
	close(pipefd[0]);
	dup2(fd_in, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd_in);
	close(pipefd[1]);
	execute_command(cmd, envv);
}

static void	last_command(char *file, char *cmd, char *envv[], int pipefd[2])
{
	int	fd_out;

	fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	close(fd_out);
	execute_command(cmd, envv);
}

static void	middle_command(char *cmd, char *envv[],
		int prev_pipe[2], int next_pipe[2])
{
	close(prev_pipe[1]);
	close(next_pipe[0]);
	dup2(prev_pipe[0], STDIN_FILENO);
	dup2(next_pipe[1], STDOUT_FILENO);
	close(prev_pipe[0]);
	close(next_pipe[1]);
	execute_command(cmd, envv);
}
