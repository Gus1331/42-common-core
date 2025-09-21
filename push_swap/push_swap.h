/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 02:56:30 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/21 18:14:46 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"

#include <limits.h>


// typedef struct s_cheapest_move
// {
// 	int	a_target;
// 	int	b_target;
// 	int	a_moves;
// 	int	b_moves;
// }	t_cheapest_move;

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

int		is_sorted(t_list *stack);
void	sort(t_list **stack_a, t_list **stack_b);

int		cheapest_rotation_to_top(t_list *stack, t_list *nbr);
t_list	*find_cheapest_to_push_b(t_list **stack_a, t_list **stack_b,
			t_list *first_a);
void	push_chepeast_to_b(t_list **stack_a, t_list **stack_b,
			t_list *cheapest);
void	push_back_to_a(t_list **stack_a, t_list **stack_b);
t_list	*get_greatest(t_list *stack);
void	align_stack(t_list **stack, enum e_stack stack_id, t_list *to_top);
t_list	*find_lowest(t_list *stack);
t_list	*find_highest(t_list *stack);

// void	push_cheapest_b(t_list **stack_a, t_list **stack_b);

void	print_ab(t_list *a, t_list *b); // teste

#endif