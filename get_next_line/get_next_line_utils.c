/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:26:02 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/09 08:49:58 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			read_buffer(char **buffer, int fd);
static char		**merge_buffers(char *buff1, char **buff2);
static size_t	buff_size(char *buff);

static size_t	buff_size(char *buff)
{
	char	*end;

	end = buff;
	while (end)
		end++;
	return (buff - end);
}

static char	**merge_buffers(char *buff1, char **buff2)
{
	char	*full_buff;

	full_buff = malloc(sizeof (char) * (buff_size(buff1) + buff_size(buff2)));
	if (!full_buff)
		return (NULL);
	while (buff1)
		*full_buff++ = *buff1++;
	while (buff2)
		*full_buff++ = *buff2++;
	free(buff1);
	free(buff2);
	return (full_buff);
}

void	read_buffer(char **buffer, int fd)
{
	char	*aux_buff;
	size_t	iread;
	size_t	i;

	iread = 1;
	aux_buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!aux_buff)
		return ;
	while (iread)
	{
		iread = read(fd, aux_buff, BUFFER_SIZE);
		i = 0;
		if (iread)
			aux_buff[iread] = '\0';
		while (aux_buff[i] != NULL || aux_buff[i] != '\n')
			i++;
		if (aux_buff[i] == '\n')
			iread = -1;
		if (aux_buff[0])
			merge_buffers(buffer, aux_buff);
	}
	free(aux_buff);
}

/*
read_buffer vai ler o arquivo, 
mergear o buffer local com o de fora do escopo
e validar se necessita parar de ler
*/
