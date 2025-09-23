/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:09:33 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/22 20:43:32 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

// static void	push_generic(t_stacks *stacks, enum e_stack stack_type)
// {
// 	t_stack	*stack_target;
// 	t_stack	*stack_opposite;
// 	if (stack_type == STACK_A)
// 	{
// 		stack_target = stacks->stack_a;
// 		stack_opposite = stacks->stack_b;
// 	}
// 	else if (stack_type == STACK_B)
// 	{
// 		stack_target = stacks->stack_b;
// 		stack_opposite = stacks->stack_a;
// 	}
// 	if (stack_opposite->stack_size > 0)
// 		push(stack_target, pop(stack_opposite));
// }
// push_generic(stacks, STACK_A);


void	pa(t_stacks *stacks)
{
	ft_printf("pa\n");
	if (stacks->stack_b->stack_size > 0)
		push(stacks->stack_a, pop(stacks->stack_b));
}

void	pb(t_stacks *stacks)
{
	ft_printf("pb\n");
	if (stacks->stack_a->stack_size > 0)
		push(stacks->stack_b, pop(stacks->stack_a));
}

