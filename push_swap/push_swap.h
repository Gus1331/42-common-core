/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 02:56:30 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/03 18:32:20 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

enum e_stack
{
	STACK_A,
	STACK_B
};

enum e_op
{
	SWAP,
	PUSH,
	ROTATE,
	RROTATE
};

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	op(t_list **stack,
			enum e_stack stack_type,
			enum e_op operation);
void	op_push(t_list **stack_a,
			t_list **stack_b,
			enum e_op operation);

int		is_sorted(t_list *stack);
void	sort(t_list **stack_a, t_list **stack_b);

void	print_ab(t_list *a, t_list *b); // teste

#endif