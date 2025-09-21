/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 06:05:59 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/21 18:14:53 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_list *stack);
void	sort(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack, enum e_stack stack_id);
int		cheapest_rotation_to_top(t_list *stack, t_list *nbr);
t_list	*get_greatest(t_list *stack);


int	is_sorted(t_list *stack)
{
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (stack->next != NULL)
		{
			if (*(int *)(stack->content) > *(int *)((stack->next)->content))
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (is_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) <= 3)
		return (sort_3(stack_a, STACK_A));
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		aux = find_cheapest_to_push_b(stack_a, stack_a, *stack_a);
		push_chepeast_to_b(stack_a, stack_b, aux);
		// push_chepeast_b(stack_a, stack_b);
	}
	sort_3(stack_a, STACK_A);
	while (*stack_b != NULL)
		push_back_to_a(stack_a, stack_b);
	align_stack(stack_a, STACK_A, get_greatest(*stack_a)->next);
}

void	sort_3(t_list **stack, enum e_stack stack_id)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*stack) == 2)
		return (op(stack, STACK_A, SWAP));
	first = *stack;
	second = first->next;
	third = second->next;
	if (*(int *)(first->content) > *(int *)(second->content))
		op(stack, stack_id, SWAP);
	first = *stack;
	second = first->next;
	third = second->next;
	if (*(int *)(second->content) > *(int *)(third->content))
		op(stack, stack_id, RROTATE);
	first = *stack;
	second = first->next;
	third = second->next;
	if (*(int *)(first->content) > *(int *)(second->content))
		op(stack, stack_id, SWAP);
}

int	cheapest_rotation_to_top(t_list *stack, t_list *nbr)
{
	int	stack_size;
	int	i;

	i = 0;
	stack_size = ft_lstsize(stack);
	while (*(int *)stack->content != *(int *)nbr->content)
	{
		i++;
		stack = stack->next;
	}
	if (i > stack_size / 2)
		return (stack_size - i);
	return (i);
}

t_list	*get_greatest(t_list *stack)
{
	t_list	*greatest;

	greatest = stack;
	stack = stack->next;
	while (stack != NULL)
	{
		if (*(int *)greatest->content < *(int *)stack->content)
			greatest = stack;
		stack = stack->next;
	}
	return (greatest);
}
