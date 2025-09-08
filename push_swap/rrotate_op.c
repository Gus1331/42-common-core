/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:55:51 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/05 23:45:58 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
static void	reverse_rotate(t_list **stack);

static void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
