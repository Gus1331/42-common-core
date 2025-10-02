/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:53:45 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 00:22:43 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_to_top(t_stack *stack, int element_index);
int			operations_to_top(t_stack *stack, t_content *content);
void		align_match(t_stacks *stacks, t_content *target_a,
				t_content *match);

void	rotate_to_top(t_stack *stack, int element_index)
{
	int	i;

	i = 0;
	if (element_index > (stack->stack_size / 2))
	{
		while (i < stack->stack_size - element_index)
		{
			rrotate_stack(stack);
			i++;
		}
	}
	else
	{
		while (i < element_index)
		{
			rotate_stack(stack);
			i++;
		}
	}
}

int	operations_to_top(t_stack *stack, t_content *content)
{
	int			to_top;
	int			i;
	t_content	*aux;

	if (stack->top == content)
		return (0);
	to_top = 0;
	i = 1;
	aux = stack->top->next;
	while (i < stack->stack_size)
	{
		if (aux == content)
		{
			if (i > (stack->stack_size / 2))
				return (i - stack->stack_size);
			else
				return (i);
		}
		aux = aux->next;
		i++;
	}
	if (aux->next == content)
		return (-1);
	return (2147483647);
}

void	align_match(t_stacks *stacks, t_content *target_a, t_content *target_b)
{
	int		a_op;
	int		b_op;

	a_op = operations_to_top(stacks->stack_a, target_a);
	b_op = operations_to_top(stacks->stack_b, target_b);
	while (a_op > 0 && b_op > 0)
	{
		rr(stacks);
		a_op--;
		b_op--;
	}
	while (a_op < 0 && b_op < 0)
	{
		rrr(stacks);
		a_op++;
		b_op++;
	}
	if (a_op >= 0)
		rotate_to_top(stacks->stack_a, a_op);
	else
		rotate_to_top(stacks->stack_a, stacks->stack_a->stack_size + a_op);
	if (b_op >= 0)
		rotate_to_top(stacks->stack_b, b_op);
	else
		rotate_to_top(stacks->stack_b, stacks->stack_b->stack_size + b_op);
}
