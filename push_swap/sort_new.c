/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:18:56 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/21 14:26:44 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void					push_chepeast_b(t_list **stack_a, t_list **stack_b);
// // static void				new_cheapest_move(t_cheapest_move *move,
// // 							int a_target, int b_target);
// static t_cheapest_move	*cheapest_move(t_list **stack_a, t_list **stack_b);
// static int				moves_to_top(t_list *stack, int target);

// static int	moves_to_top(t_list *stack, int target)
// {
// 	int	moves;

// 	moves = 0;
// 	while (*(int *)stack->content != target)
// 	{
// 		moves++;
// 		stack = stack->next;
// 	}
// 	return (moves);
// }

// // static void	new_cheapest_move(t_cheapest_move *move,
// // 				int a_target, int b_target)
// // {
// // 	move->a_target = a_target;
// // 	move->b_target = b_target;
// // 	move->a_moves = cheapest_rotation_to_top()
// // }

// static t_cheapest_move	*cheapest_move(t_list **stack_a, t_list **stack_b)
// {
// 	t_cheapest_move	*res;
// 	t_list			*aux_a;
// 	t_list			*aux_b;

// 	res = malloc(sizeof(t_cheapest_move));
// 	aux_a = *stack_a;
// 	while (aux_a != NULL)
// 	{
// 		aux_b = *stack_b;
// 		while (stack_b != NULL)
// 		{
// 			if (*(int *)aux_a->content > *(int *)aux_b->content
// 				&& *(int *)aux_a->content < *(int *)aux_b->next->content)
// 			{
// 				res->a_target = *(int *)aux_a->content;
// 				res->b_target = *(int *)aux_b->next->content;
// 				res->a_moves = moves_to_top(*stack_a, res->a_target);
// 				res->b_moves = moves_to_top(*stack_b, res->b_target);
// 			}
// 			aux_b = aux_b->next;
// 		}
// 		aux_a = aux_a->next;
// 	}
// 	return (res);
// }

// void	push_cheapest_b(t_list **stack_a, t_list **stack_b)
// {
// 	(void)stack_a;
// 	(void)stack_b;
// 	pb(stack_a, stack_b);
// }

/*

uma struct cheapest_move???? {target_a, target_b, a_moves, b_moves}


*/