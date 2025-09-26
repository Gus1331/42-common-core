/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:25:26 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/23 15:59:30 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
static void	swap(t_stack *stack);

void	sa(t_stacks *stacks)
{
	ft_printf("sa\n");
	swap(stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	ft_printf("sa\n");
	swap(stacks->stack_b);
}

void	ss(t_stacks *stacks)
{
	ft_printf("ss\n");
	swap(stacks->stack_a);
	swap(stacks->stack_b);
}

static void	swap(t_stack *stack)
{
	int	aux;

	if (stack->stack_size < 2)
		return ;
	aux = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = aux;
}
