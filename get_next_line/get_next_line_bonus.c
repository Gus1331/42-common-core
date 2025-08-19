/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:25:59 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/19 17:02:16 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	handle_buff(char **buff, char **aux)
{
	if (**aux)
		*buff = gnl_buffstr(buff, (*aux - *buff));
	else
	{
		free(*buff);
		*buff = malloc(1);
		**buff = '\0';
	}
}

static char	*next_line(char **buff)
{
	char	*res;
	char	*aux;
	size_t	i;

	aux = *buff;
	while (*aux && *aux != '\n')
		aux++;
	if (*aux == '\n')
		aux++;
	res = malloc(((aux - *buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (size_t)((aux - *buff)))
	{
		res[i] = (*buff)[i];
		i++;
	}
	res[i] = '\0';
	handle_buff(buff, &aux);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(1);
		(buffer[fd])[0] = '\0';
	}
	read_buffer(&(buffer[fd]), fd);
	if (!buffer[fd])
		return (NULL);
	if (*(buffer[fd]) == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (next_line(&(buffer[fd])));
}
