/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 03:55:43 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/01 05:40:54 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
// ss : sa and sb at the same time.

#include "push_swap.h"

void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
static void	swap(t_list **stack);

static void	swap(t_list **stack)
{
	int	*aux;

	aux = (int *)(*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = (void *)aux;
}

void	sa(t_list **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_list **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
