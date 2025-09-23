/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:14:31 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/22 21:14:35 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks			*initialize_stacks(void);
void				free_stacks(t_stacks *stacks);
void				push(t_stack *stack, int content);
int					pop(t_stack *stack);

t_stacks	*initialize_stacks(void)
{
	t_stacks	*res;

	res = ft_calloc(1, sizeof(t_stacks));
	if (!res)
		return (NULL);
	res->stack_a = ft_calloc(1, sizeof(t_stack));
	res->stack_b = ft_calloc(1, sizeof(t_stack));
	if (!res->stack_a || !res->stack_a)
		return (free_stacks(res), NULL);
	res->stack_a->stack_type = STACK_A;
	res->stack_b->stack_type = STACK_B;
	res->stack_a->stack_size = 0;
	res->stack_b->stack_size = 0;
	return (res);
}

void	push(t_stack *stack, int content)
{
	t_content	*new_node;

	new_node = (t_content *)ft_calloc(1, sizeof(t_content));
	if (!new_node)
		return ;
	new_node->content = content;
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->top->prev = new_node;
		stack->top->next = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->stack_size++;
}

int	pop(t_stack *stack)
{
	t_content	*top_node;
	int			content;

	if (stack->top == NULL || stack->stack_size == 0)
		return (0);
	top_node = stack->top;
	content = top_node->content;
	if (stack->stack_size == 1)
		stack->top = NULL;
	else
	{
		stack->top->prev->next = stack->top->next;
		stack->top->next->prev = stack->top->prev;
		stack->top = top_node->next;
	}
	free(top_node);
	stack->stack_size--;
	return (content);
}

void	free_stacks(t_stacks *stacks)
{
	while (stacks->stack_a->stack_size > 0)
		pop(stacks->stack_a);
	while (stacks->stack_b->stack_size > 0)
		pop(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
