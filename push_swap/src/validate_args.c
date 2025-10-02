/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:00:29 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/01 02:46:39 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks		*validate_argv(int argc, char *argv[]);
static int		validate_input(char *input);
static int		validate_input_limit(char *input);
static int		validate_duplicates(t_stack *stack);
static t_stacks	*handle_single_arg(char *argv[]);

static t_stacks	*handle_single_arg(char *argv[])
{
	char		**new_argv;
	t_stacks	*res;
	int			i;
	int			arg_quantity;
	char		*aux;

	aux = ft_calloc(ft_strlen(argv[1]) + 3, sizeof(char));
	aux[0] = '0';
	aux[1] = ' ';
	ft_strlcat(aux, argv[1], ft_strlen(argv[1]) + 3);
	new_argv = ft_split(aux, ' ');
	free(aux);
	if (!new_argv)
		return (NULL);
	arg_quantity = 0;
	while (new_argv[arg_quantity])
		arg_quantity++;
	res = validate_argv(arg_quantity, new_argv);
	i = 0;
	while (i < arg_quantity)
		free(new_argv[i++]);
	free(new_argv);
	return (res);
}

static int	validate_input_limit(char *input)
{
	int	i;
	int	n;

	if (ft_strlen(input) < 10)
		return (1);
	if (ft_strlen(input) > 11)
		return (0);
	n = ft_atoi(input);
	i = 0;
	if (input[0] == '-' && n > 0)
		return (0);
	else if (input[0] != '-' && n < 0)
		return (0);
	return (1);
}

static int	validate_duplicates(t_stack *stack)
{
	int			i;
	int			j;
	t_content	*aux_i;
	t_content	*aux_j;

	if (stack->top == NULL)
		return (1);
	aux_i = stack->top;
	i = 0;
	while (i++ < stack->stack_size)
	{
		j = i;
		aux_j = aux_i->next;
		while (j++ < stack->stack_size)
		{
			if ((int)aux_i->content == (int)aux_j->content)
				return (0);
			aux_j = aux_j->next;
		}
		aux_i = aux_i->next;
	}
	return (1);
}

static int	validate_input(char *input)
{
	int	i;

	i = 0;
	if (!*input)
		return (0);
	if (ft_strlen(input) == 1)
		return (ft_isdigit(input[0]));
	while (input[i])
	{
		if (ft_isdigit(input[i]) <= 0)
		{
			if (!(i == 0 && input[i] == '-'))
				return (0);
		}
		i++;
	}
	return (1);
}

t_stacks	*validate_argv(int argc, char *argv[])
{
	t_stacks	*stacks;
	int			i;

	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
		return (handle_single_arg(argv));
	i = 1;
	stacks = initialize_stacks();
	while (i < argc)
	{
		if (validate_input(argv[i]) <= 0 || validate_input_limit(argv[i]) <= 0)
			return (free_stacks(stacks), NULL);
		push(stacks->stack_a, ft_atoi(argv[i]));
		stacks->stack_a->top = stacks->stack_a->top->next;
		i++;
	}
	if (validate_duplicates(stacks->stack_a) <= 0
		|| stacks->stack_a->stack_size == 0)
		return (free_stacks(stacks), NULL);
	return (stacks);
}
