/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:18:50 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/28 22:57:27 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack);

int	is_sorted(t_stack *stack)
{
	t_content	*aux;
	int			i;

	i = 0;
	aux = stack->top;
	while (i < stack->stack_size - 1)
	{
		if (aux->content > aux->next->content)
			return (0);
		aux = aux->next;
		i++;
	}
	return (1);
}
