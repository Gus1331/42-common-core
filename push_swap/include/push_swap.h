/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:41:53 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 01:59:26 by gustaoli         ###   ########.fr       */
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

typedef struct s_content
{
	struct s_content	*prev;
	int					content;
	struct s_content	*next;
}	t_content;

typedef struct s_stack
{
	enum e_stack		stack_type;
	int					stack_size;
	struct s_content	*top;
}	t_stack;

typedef struct s_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_stacks;

/* ARGUMENT MANAGEMENT */
t_stacks	*validate_argv(int argc, char *argv[]);

/* STACKS MANAGEMENT */
t_stacks	*initialize_stacks(void);
void		push(t_stack *stack, int content);
int			pop(t_stack *stack);
void		free_stacks(t_stacks *stacks);

/* OPERATIONS */
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

/* ALIGN STACK */
void		rotate_to_top(t_stack *stack, int element_index);
void		align_match(t_stacks *stacks, t_content *cheapest,
				t_content *match);

/* GENERIC OPERATIONS */
void		rotate_stack(t_stack *stack);
void		rrotate_stack(t_stack *stack);

/* NAVIGATE STACK HELPERS */
int			lowest_index(t_stack *stack);
int			highest_index(t_stack *stack);
t_content	*get(t_stack *stack, int index);
t_content	*get_cheapest(t_stacks *stacks);
t_content	*get_cheapest_from_b(t_stacks *stacks);
t_content	*find_target_in_b(t_stacks *stacks, t_content *a_content);
t_content	*find_target_in_a(t_stacks *stacks, t_content *b_content);

/* SORT FUNCTIONS */
int			is_sorted(t_stack *stack);
void		sort_low(t_stacks *stacks);
void		sort(t_stacks *stacks);
void		push_cheapest_to_a(t_stacks *stacks);

/* CALCULATE OPERATIONS*/
int			operations_to_top(t_stack *stack, t_content *content);
int			calculate_cost_b_to_a(t_stacks *stacks, t_content *b_content);

/* BONUS OPERATIONS*/
void		pa_bonus(t_stacks *stacks);
void		pb_bonus(t_stacks *stacks);
void		rotate_bonus(t_stack *stack);
void		rr_bonus(t_stacks *stacks);
void		rrotate_bonus(t_stack *stack);
void		rrr_bonus(t_stacks *stacks);
void		ss_bonus(t_stacks *stacks);
void		swap_bonus(t_stack *stack);

#endif