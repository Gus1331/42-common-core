/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:58 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/10 12:52:12 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc > 1)
	{
		while (argc > i)
		{
			j = 0;
			while (argv[i][j])
			{
				ft_putchar(argv[i][j++]);
			}
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
