/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:25:59 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/16 20:55:53 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TESTE

char		*get_next_line(int fd);
static char	*next_line(char **buff);
static void	handle_buff(char **buff, char **aux);

static void	handle_buff(char **buff, char **aux)
{
	//printf("I handle_buff buff= {%s}, aux= {%s}\n", *buff, *aux);
	if (**aux)
		*buff = gnl_buffstr(buff, (*aux - *buff));
	else
	{
		free(*buff);
		*buff = malloc(1);
		**buff = '\0';
	}
	//printf("F handle_buff buff= {%s}, aux= {%s}\n", *buff, *aux);
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
// retorna a next line caso tenha após ler todo o buffer
// substitui o conteudo do buffer caso encontre \n para o resto não retornado

char	*get_next_line(int fd)
{
	static char	*buffer;
	printf("buff => {%s}\n", buffer);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
		read_buffer(&buffer, fd);
	}
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
int main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir arquivo");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("RESULT -> {%s}\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
