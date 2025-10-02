/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:38:06 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 01:55:05 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_bonus(t_stacks *stacks);
void	swap_bonus(t_stack *stack);

void	ss_bonus(t_stacks *stacks)
{
	swap_bonus(stacks->stack_a);
	swap_bonus(stacks->stack_b);
}

void	swap_bonus(t_stack *stack)
{
	int	aux;

	if (stack->stack_size < 2)
		return ;
	aux = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = aux;
}
