/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:54:11 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/18 15:53:10 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayf.h"

int	display_file_name(char *fname);

int	display_file_name(char *fname)
{
	ssize_t	buffread;
	char	buff[1024];
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (1);
	buffread = read(fd, buff, 1);
	while (buffread)
	{
		write(1, buff, 1);
		buffread = read(fd, buff, 1);
	}
	close(fd);
	return (0);
}
