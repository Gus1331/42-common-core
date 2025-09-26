/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:10 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/25 16:06:07 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lowest_index(t_stack *stack);
int			highest_index(t_stack *stack);
t_content	*get(t_stack *stack, int index);

t_content	*get(t_stack *stack, int index)
{
	int			i;
	t_content	*aux;

	if (index > stack->stack_size || index < 0)
		return (NULL);
	aux = stack->top;
	i = -1;
	while (++i < index)
		aux = aux->next;
	return (aux);
}

int	highest_index(t_stack *stack)
{
	t_content	*aux;
	int			high_index;
	int			high_value;
	int			i;

	if (stack->stack_size <= 1)
		return (0);
	aux = stack->top;
	i = -1;
	high_index = 0;
	high_value = aux->content;
	while (++i < stack->stack_size)
	{
		if (aux->content > high_value)
		{
			high_value = aux->content;
			high_index = i;
		}
		aux = aux->next;
	}
	return (high_index);
}

int	lowest_index(t_stack *stack)
{
	t_content	*aux;
	int			low_index;
	int			low_value;
	int			i;

	if (stack->stack_size <= 1)
		return (0);
	aux = stack->top;
	i = -1;
	low_index = 0;
	low_value = aux->content;
	while (++i < stack->stack_size)
	{
		if (aux->content < low_value)
		{
			low_value = aux->content;
			low_index = i;
		}
		aux = aux->next;
	}
	return (low_index);
}

