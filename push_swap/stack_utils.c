/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 04:28:24 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/21 17:05:11 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_stack(t_list **stack, enum e_stack stack_id, t_list *to_top);
t_list	*find_lowest(t_list *stack);
t_list	*find_highest(t_list *stack);

t_list	*find_lowest(t_list *stack)
{
	t_list	*lowest;

	lowest = stack;
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			if (*(int *)lowest->content > *(int *)stack->content)
				lowest = stack;
			stack = stack->next;
		}
	}
	return (lowest);
}

t_list	*find_highest(t_list *stack)
{
	t_list	*highest;

	highest = stack;
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			if (*(int *)highest->content < *(int *)stack->content)
				highest = stack;
			stack = stack->next;
		}
	}
	return (highest);
}

void	align_stack(t_list **stack, enum e_stack stack_id, t_list *to_top)
{
	int		i;
	t_list	*aux;

	if (to_top == NULL)
		return ;
	aux = *stack;
	i = 0;
	while (*(int *)aux->content != *(int *)to_top->content)
	{
		i++;
		aux = aux->next;
	}
	if (i < (ft_lstsize(*stack) / 2) + 1)
	{
		while (*(int *)(*stack)->content != *(int *)to_top->content)
			op(stack, stack_id, ROTATE);
	}
	else
	{
		while (*(int *)(*stack)->content != *(int *)to_top->content)
			op(stack, stack_id, RROTATE);
	}
}
