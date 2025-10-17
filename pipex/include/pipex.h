/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:29:34 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/17 04:31:22 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h> 
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

char	**get_bin_paths(char **envv);
void	free_paths(char **paths);
void	validate_cmds(int argc, char **argv, char **envv);
void	run_mid_commands(char *argv[], char *envv[],
			int prev_pipe[2], int next_pipe[2]);
char	*verify_cmd_in_bin_paths(char *cmd, char **bin_paths);
void	execute_command(char *cmd, char *envv[]);
void	wait_child(void);
char	**get_args(char *cmd);

int		here_doc(int argc, char *argv[], char *envv[]);

#endif
