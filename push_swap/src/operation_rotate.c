/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:27:29 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/23 15:22:55 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
static void	rotate(t_stack *stack);

void	ra(t_stacks *stacks)
{
	ft_printf("ra\n");
	rotate(stacks->stack_a);
}

void	rb(t_stacks *stacks)
{
	ft_printf("rb\n");
	rotate(stacks->stack_b);
}

void	rr(t_stacks *stacks)
{
	ft_printf("rr\n");
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
}

static void	rotate(t_stack *stack)
{
	stack->top = stack->top->next;
}
