/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:10 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 00:14:26 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					lowest_index(t_stack *stack);
int					highest_index(t_stack *stack);
t_content			*get(t_stack *stack, int index);
t_content			*find_target_in_a(t_stacks *stacks, t_content *b_content);
static t_content	*verify_new_lowest_or_highest(t_stack *oposite_stack,
						t_content *target);

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

t_content	*find_target_in_a(t_stacks *stacks, t_content *b_content)
{
	t_content	*aux;
	t_content	*target;
	int			min_diff;
	int			i;

	target = verify_new_lowest_or_highest(stacks->stack_a, b_content);
	if (target != NULL)
		return (target);
	min_diff = 2147483647;
	aux = stacks->stack_a->top;
	i = -1;
	while (++i < stacks->stack_a->stack_size)
	{
		if (aux->content > b_content->content)
		{
			if (aux->content - b_content->content < min_diff)
			{
				min_diff = aux->content - b_content->content;
				target = aux;
			}
		}
		aux = aux->next;
	}
	return (target);
}

static t_content	*verify_new_lowest_or_highest(t_stack *oposite_stack,
						t_content *target)
{
	t_content	*lowest;
	t_content	*highest;

	lowest = get(oposite_stack, lowest_index(oposite_stack));
	if (target->content < lowest->content)
		return (lowest);
	highest = get(oposite_stack, highest_index(oposite_stack));
	if (target->content > highest->content)
		return (lowest);
	return (NULL);
}
