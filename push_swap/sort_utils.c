/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:18:18 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/21 19:05:11 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list			*find_cheapest_to_push_b(t_list **stack_a, t_list **stack_b,
					t_list *first_a);
void			push_chepeast_to_b(t_list **stack_a, t_list **stack_b,
					t_list *cheapest);
void			push_back_to_a(t_list **stack_a, t_list **stack_b);
static t_list	*find_match_pos(t_list *stack, t_list *target);
// static void		update_cheapest(t_list **cheapest_pointer, t_list *new_cheapest,
// 					int *operation_pointer, int operation_value);
// static t_list	*validate_cheapest(t_list *cheapest, t_list *stack);
// t_list	*find_cheapest_to_push_b(t_list **stack_a, t_list **stack_b,
// 	t_list *first_a, t_list *first_b)
// {
// 	t_list	*cheapest;
// 	int		ops;
// 	int		op_a;
// 	int		op_b;

// 	ops = 0;
// 	cheapest = first_a;
// 	while (first_a != NULL)
// 	{
// 		op_a = cheapest_rotation_to_top(*stack_a, first_a);
// 		op_b = 0;
// 		first_b = *stack_b;
// 		while (first_b != NULL)
// 		{
// 			if (first_b->next == NULL)
// 				break ;
// 			if (*(int *)first_a->content < *(int *)first_b->content
// 				&& *(int *)first_a->content > *(int *)(first_b->next)->content)
// 			{
// 				op_b = cheapest_rotation_to_top(*stack_b, first_b->next);
// 			}
// 			first_b = first_b->next;
// 		}
// 		if (ops > (op_a + op_b) || ops == 0)
// 			update_cheapest(&cheapest, first_a, &ops, op_a + op_b);
// 		first_a = first_a->next;
// 	}
// 	return (validate_cheapest(cheapest, *stack_a));
// }
t_list	*find_cheapest_to_push_b(t_list **stack_a,
	t_list **stack_b, t_list *first_a)
{
	t_list	*cheapest;
	int		op_b;
	int		cheap_op;
	t_list	*aux;

	cheap_op = 0;
	while (first_a != NULL)
	{
		aux = find_match_pos(*stack_b, first_a);
		op_b = cheapest_rotation_to_top(*stack_b, aux);
		if (cheapest_rotation_to_top(*stack_a, first_a) + op_b < cheap_op
			|| cheap_op == 0)
		{
			cheapest = first_a;
			cheap_op = cheapest_rotation_to_top(*stack_a, first_a) + op_b;
		}
		first_a = first_a->next;
	}
	return (cheapest);
}

static t_list	*find_match_pos(t_list *stack, t_list *target)
{
	t_list	*res;

	res = stack;
	if (*(int *)target->content > *(int *)find_highest(stack)->content
		|| *(int *)target->content < *(int *)find_lowest(stack)->content)
		return (find_highest(stack));
	while (stack != NULL)
	{
		if (stack->next != NULL)
		{
			if (*(int *)target->content < *(int *)stack->content
				&& *(int *)target->content > *(int *)stack->next->content)
				return (stack->next);
		}
		stack = stack->next;
	}
	return (res);
}

void	push_chepeast_to_b(t_list **stack_a, t_list **stack_b,
			t_list *cheapest)
{
	t_list	*aux;

	align_stack(stack_a, STACK_A, cheapest);
	aux = *stack_b;
	while (aux != NULL)
	{
		if (aux->next != NULL
			&& *(int *)cheapest->content < *(int *)aux->content
			&& *(int *)cheapest->content > *(int *)aux->next->content)
		{
			align_stack(stack_b, STACK_B, aux->next);
			break ;
		}
		aux = aux->next;
	}
	if (*(int *)cheapest->content > *(int *)find_highest(*stack_b)->content
		|| *(int *)cheapest->content < *(int *)find_lowest(*stack_b)->content)
		align_stack(stack_b, STACK_B, find_highest(*stack_b));
	pb(stack_a, stack_b);
}

// static void	update_cheapest(t_list **cheapest_pointer, t_list *new_cheapest,
// 	int *operation_pointer, int operation_value)
// {
// 	*cheapest_pointer = new_cheapest;
// 	*operation_pointer = operation_value;
// }

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;
	int		top_value;
	t_list	*greatest_a;

	greatest_a = get_greatest(*stack_a);
	if (*stack_b == NULL)
		return ;
	aux = *stack_a;
	top_value = *(int *)(*stack_b)->content;
	while (aux != NULL)
	{
		if (aux->next != NULL && top_value > *(int *)aux->content
			&& top_value < *(int *)aux->next->content)
		{
			align_stack(stack_a, STACK_A, aux->next);
			break ;
		}
		aux = aux->next;
	}
	if (aux == NULL && top_value > *(int *)greatest_a->content)
		align_stack(stack_a, STACK_A, greatest_a->next);
	if (aux == NULL && top_value < *(int *)ft_lstlast(*stack_a)->content
		&& top_value < *(int *)greatest_a->content)
		align_stack(stack_a, STACK_A, greatest_a->next);
	pa(stack_a, stack_b);
}

// static t_list	*validate_cheapest(t_list *cheapest, t_list *stack)
// {
// 	t_list	*low_stack;
// 	t_list	*high_stack;

// 	low_stack = find_lowest(stack);
// 	high_stack = find_highest(stack);
// 	if (*(int *)cheapest->content < *(int *)low_stack->content)
// 		return (high_stack);
// 	if (*(int *)cheapest->content > *(int *)high_stack->content)
// 		return (low_stack);
// 	return (cheapest);
// }


// 24 3 21 16 19 46 34 30 25 7 9 37 40 2 4 42 18 43 15 45 48 36 10 27 49 29 14 39 33 47 8 28 38 32 23 5 31 1 26 11 20 6 12 22 35 44 13 17 41 50 