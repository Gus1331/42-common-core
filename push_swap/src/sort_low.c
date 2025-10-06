/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:16:38 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 08:04:23 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_low(t_stacks *stacks);
void	sort_3(t_stacks *stacks);

void	sort_low(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a))
		return ;
	else if (stacks->stack_a->stack_size == 2)
		sa(stacks);
	else if (stacks->stack_a->stack_size == 3)
		sort_3(stacks);
}

void	sort_3(t_stacks *stacks)
{
	t_stack	*stack;

	stack = stacks->stack_a;
	if (stack->top->content > stack->top->next->content
		&& stack->top->content < stack->top->prev->content)
		sa(stacks);
	else if (stack->top->content > stack->top->prev->content
		&& stack->top->content < stack->top->next->content)
		rra(stacks);
	else if (stack->top->content < stack->top->next->content
		&& stack->top->next->content > stack->top->prev->content)
	{
		ra(stacks);
		sa(stacks);
		rra(stacks);
	}
	else if (stack->top->content > stack->top->next->content
		&& stack->top->next->content > stack->top->prev->content)
	{
		sa(stacks);
		rra(stacks);
	}
	else
		ra(stacks);
}
