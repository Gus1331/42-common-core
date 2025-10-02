/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:09:33 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/01 22:29:17 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

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
