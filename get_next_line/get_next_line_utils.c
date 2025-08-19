/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:26:02 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/19 17:01:28 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	buff_size(char *buff)
{
	size_t	len;

	len = 0;
	while (buff && buff[len])
		len++;
	return (len);
}

static int	has_nl(char *buff)
{
	while (*buff)
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

char	*gnl_buffstr(char **buff, unsigned int start)
{
	char	*res;
	size_t	i;
	size_t	buff_len;

	buff_len = buff_size(&(*buff)[start]);
	if (start > buff_size(*buff))
	{
		res = malloc(1);
		return (res[0] = '\0', res);
	}
	res = malloc(buff_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < buff_len)
	{
		res[i] = (*buff)[start + i];
		i++;
	}
	res[i] = '\0';
	free(*buff);
	return (res);
}

static char	*merge_buffers(char **buff1, char **buff2)
{
	char	*buff;
	char	*buff_i;
	int		i;

	buff = malloc(sizeof(char) * (buff_size(*buff1) + buff_size(*buff2) + 1));
	if (!buff)
		return (NULL);
	buff_i = buff;
	i = 0;
	while ((*buff1)[i])
	{
		*buff_i++ = (*buff1)[i];
		i++;
	}
	i = 0;
	while ((*buff2)[i])
	{
		*buff_i++ = (*buff2)[i];
		i++;
	}
	*buff_i = '\0';
	free(*buff1);
	return (buff);
}

void	read_buffer(char **buffer, int fd)
{
	char	*aux_buff;
	ssize_t	iread;

	aux_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux_buff)
		return ;
	iread = 1;
	while (iread && has_nl(*buffer) == 0)
	{
		iread = read(fd, aux_buff, BUFFER_SIZE);
		if (iread == -1)
		{
			free(aux_buff);
			free(*buffer);
			*buffer = NULL;
			return ;
		}
		aux_buff[iread] = '\0';
		*buffer = merge_buffers(buffer, &aux_buff);
	}
	free(aux_buff);
}
