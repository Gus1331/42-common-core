/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:41:49 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/22 19:33:20 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 1)
		return (0);
	stacks = validate_argv(argc, argv);
	if (stacks == NULL)
		return (ft_printf("Input error!"), 1);
	// ft_printf("Hello World!\n");
	t_content	*aux = stacks->stack_a->top;
	for(int i = 0; i < stacks->stack_a->stack_size; i++){
		ft_printf("%d, ", (int)aux->content);
		aux = aux->next;
	}
	free_stacks(stacks);
	return (0);
}
