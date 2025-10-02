/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:41:49 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/01 22:29:55 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_stacks(t_stacks *stacks)
{
	t_content	*aux;

	aux = stacks->stack_a->top;
	ft_printf("STACK_A {");
	for (int i = 0; i < stacks->stack_a->stack_size; i++){
		if (i + 1 == stacks->stack_a->stack_size)
			ft_printf("%d", (int)aux->content);
		else
			ft_printf("%d, ", (int)aux->content);
		aux = aux->next;
	}
	ft_printf("}\nSTACK_B {");
	aux = stacks->stack_b->top;
	for (int i = 0; i < stacks->stack_b->stack_size; i++){
		if (i + 1 == stacks->stack_b->stack_size)
			ft_printf("%d", (int)aux->content);
		else
			ft_printf("%d, ", (int)aux->content);
		aux = aux->next;
	}
	ft_printf("}\n\n");
} */

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 1)
		return (0);
	stacks = validate_argv(argc, argv);
	if (stacks == NULL)
		return (ft_printf("Error"), 1);
	sort(stacks);
	free_stacks(stacks);
	return (0);
}
