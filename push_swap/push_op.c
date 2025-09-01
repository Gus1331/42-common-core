/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 04:42:20 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/01 11:16:33 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pa (push a): Take the first element at the top 
// of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top 
// of a and put it at the top of b.
// Do nothing if a is empty.

#include "push_swap.h"

void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
static void	push(t_list **stack1, t_list **stack2);

static void	push(t_list **stack, t_list **stack2)
{
	t_list	*stack_aux;

	if (*stack2 != NULL)
	{
		stack_aux = (*stack2)->next;
		(*stack2)->next = *stack;
		*stack = *stack2;
		*stack2 = stack_aux;
	}
}

void	pa(t_list **a, t_list **b)
{
	ft_printf("pa\n");
	push(a, b);
}

void	pb(t_list **a, t_list **b)
{
	ft_printf("pb\n");
	push(b, a);
}
