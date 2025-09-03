/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:21:07 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/03 16:21:37 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op(t_list **stack,
			enum e_stack stack_type,
			enum e_op operation);

void	op(t_list **stack,
	enum e_stack stack_type,
	enum e_op operation)
{
	if (stack_type == STACK_A)
	{
		if (operation == SWAP)
			sa(stack);
		else if (operation == ROTATE)
			ra(stack);
		else if (operation == RROTATE)
			rra(stack);
	}
	else if (stack_type == STACK_B)
	{
		if (operation == SWAP)
			sb(stack);
		else if (operation == ROTATE)
			rb(stack);
		else if (operation == RROTATE)
			rrb(stack);
	}
}
