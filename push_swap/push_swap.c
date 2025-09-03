/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 02:32:35 by gustaoli          #+#    #+#             */
/*   Updated: 2025/09/03 19:01:24 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate_argv(char *argv[]);

static void	validate_argv(char *argv[])
{
	int	i;

	argv++;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if (ft_isdigit((*argv)[i]) == 0 && (*argv)[i] != '-')
			{
				ft_printf("Input Error!");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		argv++;
	}
}

void	print_ab(t_list *a, t_list *b)
{
	t_list	*aux;

	ft_printf("\nA [");
	if (a != NULL)
	{
		ft_printf("%d", *((int *)(a->content)));
		aux = a->next;
		while (aux != NULL)
		{
			ft_printf(", %d", *(int *)(aux->content));
			aux = aux->next;
		}
	}
	ft_printf("]\nB [");
	if (b != NULL)
	{
		ft_printf("%d", *(int *)(b->content));
		aux = b->next;
		while (aux != NULL)
		{
			ft_printf(", %d", *(int *)(aux->content));
			aux = aux->next;
		}
	}
	ft_printf("]\n\n");
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	validate_argv(argv);
	i = 2;
	a = ft_lstnewnbr(ft_atoi(argv[1]));
	while (i < argc)
	{
		ft_lstadd_frontnewnbr(&a, ft_atoi(argv[i++]));
	}
	b = NULL;
	//print_ab(a, b);
	sort(&a, &b);
	//print_ab(a, b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}