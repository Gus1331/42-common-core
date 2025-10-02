/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 01:51:18 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 00:02:52 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*get_cheapest_from_b(t_stacks *stacks);
void		push_cheapest_to_a(t_stacks *stacks);
int			calculat_cost_b_to_a(t_stacks *stacks, t_content *b_content);

t_content	*get_cheapest_from_b(t_stacks *stacks)
{
	t_content	*aux;
	t_content	*cheapest;
	int			min_cost;
	int			cost;
	int			i;

	if (stacks->stack_b->stack_size == 0)
		return (NULL);
	aux = stacks->stack_b->top;
	cheapest = aux;
	min_cost = calculate_cost_b_to_a(stacks, aux);
	i = 1;
	while (i < stacks->stack_b->stack_size)
	{
		aux = aux->next;
		cost = calculate_cost_b_to_a(stacks, aux);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = aux;
		}
		i++;
	}
	return (cheapest);
}

void	push_cheapest_to_a(t_stacks *stacks)
{
	t_content	*cheapest;
	t_content	*target;

	cheapest = get_cheapest_from_b(stacks);
	if (!cheapest)
		return ;
	target = find_target_in_a(stacks, cheapest);
	align_match(stacks, target, cheapest);
	pa(stacks);
}

int	calculate_cost_b_to_a(t_stacks *stacks, t_content *b_content)
{
	t_content	*target;
	int			cost_a;
	int			cost_b;

	cost_b = operations_to_top(stacks->stack_b, b_content);
	target = find_target_in_a(stacks, b_content);
	cost_a = operations_to_top(stacks->stack_a, target);
	if (cost_a >= 0 && cost_b >= 0)
		return (ft_max(cost_a, cost_b));
	else if (cost_a <= 0 && cost_b <= 0)
		return (-ft_min(cost_a, cost_b));
	else
		return (ft_positive(cost_a) + ft_positive(cost_b));
}
