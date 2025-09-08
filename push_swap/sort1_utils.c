/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:18:18 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/08 06:28:52 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*find_cheapest_to_push_b(t_list **stack_a, t_list **stack_b,
				t_list *first_a, t_list *first_b);
void		push_chepeast_to_b(t_list **stack_a, t_list **stack_b,
				t_list *cheapest);
void		push_back_to_a(t_list **stack_a, t_list **stack_b);
void		align_stack(t_list **stack, enum e_stack stack_id, t_list *to_top);
static void	update_cheapest(t_list **cheapest_pointer, t_list *new_cheapest,
				int *operation_pointer, int operation_value);



t_list	*find_cheapest_to_push_b(t_list **stack_a, t_list **stack_b,
	t_list *first_a, t_list *first_b)
{
	t_list	*cheapest;
	int		operations;
	int		op_a;
	int		op_b;

	operations = 1;
	op_b = 1;
	cheapest = *stack_b;
	while (first_a != NULL)
	{
		op_a = cheapest_rotation_to_top(*stack_a, first_a);
		first_b = *stack_b;
		while (first_b != NULL)
		{
			if (first_b->next == NULL)
				break ;
			if (first_b->next != NULL
				&& *(int *)first_a->content < *(int *)first_b->content
				&& *(int *)first_a->content > *(int *)(first_b->next)->content)
				op_b = cheapest_rotation_to_top(*stack_b, first_b->next);
			first_b = first_b->next;
		}
		if (op_a + op_b + 1 > operations && operations > 0)
			update_cheapest(&cheapest, first_a, &operations, op_a + op_b + 1);
		first_a = first_a->next;
	}
	return (cheapest);
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
			align_stack(stack_b, STACK_B, aux);
			break ;
		}
		aux = aux->next;
	}
	pb(stack_a, stack_b);
}

static void	update_cheapest(t_list **cheapest_pointer, t_list *new_cheapest,
	int *operation_pointer, int operation_value)
{
	*cheapest_pointer = new_cheapest;
	*operation_pointer = operation_value;
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
	if (i < ft_lstsize(*stack) / 2)
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
