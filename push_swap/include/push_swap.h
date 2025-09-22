/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:41:53 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/22 17:46:12 by gustaoli         ###   ########.fr       */
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

t_stacks	*validate_argv(int argc, char *argv[]);
t_stacks	*initialize_stacks(void);
void		push(t_stack *stack, int content);
int			pop(t_stack *stack);
void		free_stacks(t_stacks *stacks);

#endif