/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:07:17 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/10 20:32:48 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	verify_fds(int fd1, int fd2);

void	verify_fds(int fd1, int fd2)
{
	if (fd1 < 0 || fd2 < 0)
	{
		close(fd1);
		close(fd2);
		ft_printf("File error!\n");
		exit(EXIT_FAILURE);
	}
}
