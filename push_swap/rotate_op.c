/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:47:11 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/01 11:10:43 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

#include "push_swap.h"

void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
static void	rotate(t_list **stack);

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	prev = *stack;
	while (prev->next)
		prev = prev->next;
	prev->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_list **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_list **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
