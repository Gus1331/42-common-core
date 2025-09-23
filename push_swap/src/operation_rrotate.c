/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:27:29 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/22 20:43:19 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
static void	rrotate(t_stack *stack);

void	rra(t_stacks *stacks)
{
	ft_printf("rra\n");
	rrotate(stacks->stack_a);
}

void	rrb(t_stacks *stacks)
{
	ft_printf("rrb\n");
	rrotate(stacks->stack_b);
}

static void	rrotate(t_stack *stack)
{
	stack->top = stack->top->prev;
}
