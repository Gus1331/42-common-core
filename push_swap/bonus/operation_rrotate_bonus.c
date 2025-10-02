/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:38:19 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 03:26:43 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_bonus(t_stacks *stacks);
void	rrotate_bonus(t_stack *stack);

void	rrr_bonus(t_stacks *stacks)
{
	rrotate_bonus(stacks->stack_a);
	rrotate_bonus(stacks->stack_b);
}

void	rrotate_bonus(t_stack *stack)
{
	if (stack->stack_size == 0)
		return ;
	stack->top = stack->top->prev;
}
