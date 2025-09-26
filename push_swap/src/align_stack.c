/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:53:45 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/26 19:19:10 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_stack *stack, int element_index);

void	rotate_to_top(t_stack *stack, int element_index)
{
	int	i;

	i = 0;
	if (element_index > (stack->stack_size / 2) + 1)
	{
		while ((stack->stack_size) - i >= element_index)
		{
			rrotate_stack(stack);
			i++;
		}
	}
	else
	{
		while (i < element_index - 1)
		{
			rotate_stack(stack);
			i++;
		}
	}
}
