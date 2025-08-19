/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:25:59 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/19 17:00:43 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	read_buffer(&buffer, fd);
	if (!buffer)
		return (NULL);
	if (*buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (next_line(&buffer));
}
