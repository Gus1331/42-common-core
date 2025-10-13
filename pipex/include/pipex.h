/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 23:29:34 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/13 02:58:31 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h> 
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

/* PATHS */
char	**get_bin_paths(char **envv);
void	free_paths(char **paths);

/* FILE DESCRIPTORS */
void	verify_fds(int fd1, int fd2);

/* COMMANDS */
char	*verify_cmd_in_bin_paths(char *cmd, char **bin_paths);
void	execute_command(char *cmd, char *envv[]);

/* FORMAT ARG */
char	**get_args(char *cmd);

#endif
