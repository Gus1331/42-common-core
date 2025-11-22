/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:30:02 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/22 15:36:19 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	*global_rules;

	if (argc < 5 || argc > 6)
		return (1);
	global_rules = init_data(argc, ++argv);
	if (!global_rules)
		return (1);
	printf("Hello World!\n");
	free(global_rules);
	return (0);
}
