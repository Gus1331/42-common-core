/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:51:53 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/02 03:48:07 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute(t_stacks *stacks, char *input);

static int	execute(t_stacks *stacks, char *input)
{
	if (ft_strncmp(input, "pa\n", 3) == 0)
		pa_bonus(stacks);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		pb_bonus(stacks);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		rotate_bonus(stacks->stack_a);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		rotate_bonus(stacks->stack_b);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		rr_bonus(stacks);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		rrotate_bonus(stacks->stack_a);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		rrotate_bonus(stacks->stack_b);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		rrr_bonus(stacks);
	else if (ft_strncmp(input, "sa\n", 3) == 0)
		swap_bonus(stacks->stack_a);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		swap_bonus(stacks->stack_b);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		ss_bonus(stacks);
	else
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	char		*input;

	if (argc < 2)
		return (0);
	stacks = validate_argv(argc, argv);
	if (stacks == NULL)
		return (ft_printf("Error"), 1);
	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (execute(stacks, input))
			return (ft_printf("Error\n"));
		free(input);
	}
	if (is_sorted(stacks->stack_a) && stacks->stack_b->stack_size == 0)
		return (ft_printf("OK"), 0);
	else
		return (ft_printf("KO"));
	free_stacks(stacks);
	return (0);
}
