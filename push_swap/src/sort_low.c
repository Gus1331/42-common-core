/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:16:38 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/28 22:55:56 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_low(t_stacks *stacks);
void	sort_3(t_stacks *stacks);
void	sort_4(t_stacks *stacks);

void	sort_low(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a))
		return ;
	else if (stacks->stack_a->stack_size == 2)
		sa(stacks);
	else if (stacks->stack_a->stack_size == 3)
		sort_3(stacks);
	else if (stacks->stack_a->stack_size == 4)
		sort_4(stacks);
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

void	sort_4(t_stacks *stacks)
{
	t_stack	*stack;

	stack = stacks->stack_a;
	while (is_sorted(stack) <= 0)
	{
		if (stack->top->content > stack->top->next->content
			&& get(stack, highest_index(stack)) != stack->top)
			sa(stacks);
		else
			ra(stacks);
	}
}

/*
ordenar de 2 até 4
*/