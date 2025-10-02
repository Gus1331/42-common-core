/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:18:50 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/01 22:55:05 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					is_sorted(t_stack *stack);
void				sort(t_stacks *stacks);

int	is_sorted(t_stack *stack)
{
	t_content	*aux;
	int			i;

	i = 0;
	aux = stack->top;
	while (i < stack->stack_size - 1)
	{
		if (aux->content > aux->next->content)
			return (0);
		aux = aux->next;
		i++;
	}
	return (1);
}

void	sort(t_stacks *stacks)
{
	if (stacks->stack_a->stack_size < 4)
		return (sort_low(stacks));
	if (is_sorted(stacks->stack_a))
		return ;
	while (stacks->stack_a->stack_size > 3)
		pb(stacks);
	sort_low(stacks);
	while (stacks->stack_b->stack_size > 0)
		push_cheapest_to_a(stacks);
	rotate_to_top(stacks->stack_a, lowest_index(stacks->stack_a));
}
