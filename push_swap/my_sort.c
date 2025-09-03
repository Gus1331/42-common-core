/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:31:01 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/03 19:29:25 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This excedes the minimum operations for project validation */

int				is_sorted(t_list *stack);
void			sort(t_list **stack_a, t_list **stack_b);
static t_list	*get_minor(t_list **stack);
static t_list	*get_greater(t_list **stack);
static void		check_and_swap(t_list **stack,
					t_list *(*f)(t_list **),
					enum e_stack s);

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
	while (is_sorted(*stack_a) == 0)
	{
		while (*stack_a != NULL)
		{
			check_and_swap(stack_a, get_minor, STACK_A);
			pb(stack_a, stack_b);
			check_and_swap(stack_b, get_greater, STACK_B);
		}
		while (*stack_b != NULL)
		{
			check_and_swap(stack_b, get_greater, STACK_B);
			pa(stack_a, stack_b);
			check_and_swap(stack_a, get_minor, STACK_A);
		}
	}
}

static t_list	*get_minor(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*second;

	first = (*stack);
	if (first == NULL)
		return (NULL);
	second = ((*stack)->next);
	if (second == NULL)
		return (first);
	last = ft_lstlast(*stack);
	if (*(int *)(second->content) == *(int *)(last->content))
	{
		if (*(int *)(first->content) < *(int *)(second->content))
			return (first);
		return (second);
	}
	if (*(int *)(first->content) < *(int *)(second->content)
	&& *(int *)(first->content) < *(int *)(last->content))
		return (first);
	else if (*(int *)(second->content) < *(int *)(last->content))
		return (second);
	return (last);
}

static t_list	*get_greater(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*second;

	first = (*stack);
	if (first == NULL)
		return (NULL);
	second = ((*stack)->next);
	if (second == NULL)
		return (first);
	last = ft_lstlast(*stack);
	if (*(int *)(second->content) == *(int *)(last->content))
	{
		if (*(int *)(first->content) > *(int *)(second->content))
			return (first);
		return (second);
	}
	if (*(int *)(first->content) > *(int *)(second->content)
	&& *(int *)(first->content) > *(int *)(last->content))
		return (first);
	else if (*(int *)(second->content) > *(int *)(last->content))
		return (second);
	return (last);
}

static void	check_and_swap(t_list **stack,
	t_list *(*f)(t_list **),
	enum e_stack stack_type)
{
	t_list	*match;
	t_list	*first;
	t_list	*second;

	first = (*stack);
	if (first == NULL)
		return ;
	second = ((*stack)->next);
	if (second == NULL)
		return ;
	match = f(stack);
	if (*(int *)(match->content) == *(int *)(first->content))
		return ;
	else if (*(int *)(match->content) == *(int *)(second->content))
		op(stack, stack_type, SWAP);
	else
		op(stack, stack_type, RROTATE);
}
