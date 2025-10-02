/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:37:52 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 03:26:33 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_bonus(t_stacks *stacks);
void	rotate_bonus(t_stack *stack);

void	rr_bonus(t_stacks *stacks)
{
	rotate_bonus(stacks->stack_a);
	rotate_bonus(stacks->stack_b);
}

void	rotate_bonus(t_stack *stack)
{
	if (stack->stack_size == 0)
		return ;
	stack->top = stack->top->next;
}
