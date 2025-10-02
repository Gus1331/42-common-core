/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 01:32:09 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 01:52:41 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_bonus(t_stacks *stacks);
void	pb_bonus(t_stacks *stacks);

void	pa_bonus(t_stacks *stacks)
{
	if (stacks->stack_b->stack_size > 0)
		push(stacks->stack_a, pop(stacks->stack_b));
}

void	pb_bonus(t_stacks *stacks)
{
	if (stacks->stack_a->stack_size > 0)
		push(stacks->stack_b, pop(stacks->stack_a));
}
