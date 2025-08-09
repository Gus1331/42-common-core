/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:25:59 by gustaoli          #+#    #+#             */
/*   Updated: 2025/08/09 08:16:37 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(sizeof(char));
	if (!buffer)
		return (NULL);
	read_buffer(&buffer, fd);
	if (!buffer)
		return (NULL);
	if (*buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (next_line(&buffer, fd));
	// retorna a next line caso tenha após ler todo o buffer
	// substitui o conteudo do buffer caso encontre \n para o resto não retornado
}
