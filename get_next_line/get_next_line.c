/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:25:59 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/12 18:33:03 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TESTE

char		*get_next_line(int fd);
static char	*next_line(char **buff);

static char	*next_line(char **buff)
{
	char	*res;
	char	*aux;
	size_t	i;

	aux = *buff;
	while (*aux && *aux != '\n')
		aux++;
	res = malloc(((aux - *buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < (size_t)((aux - *buff)))
	{
		printf("#");
		res[i] = *buff[i];
		i++;
	}
	*buff = gnl_buffstr(*buff, *buff - (aux + 1));
	printf("next_line OK\n");
	return (res);
}
// retorna a next line caso tenha após ler todo o buffer
// substitui o conteudo do buffer caso encontre \n para o resto não retornado

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
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

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("-> %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
