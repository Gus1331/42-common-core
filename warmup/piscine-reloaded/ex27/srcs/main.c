/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:53:47 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/18 15:55:59 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayf.h"

void	file_name_missing(void);
void	too_many_arguments(void);
int		main(int argc, char **argv);

void	file_name_missing(void)
{
	write(1, "File name missing.\n", 19);
}

void	too_many_arguments(void)
{
	write(1, "Too many arguments.\n", 20);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
			file_name_missing();
		else
			too_many_arguments();
		return (1);
	}
	return (display_file_name(argv[1]));
}
