/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:56:50 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/30 19:18:42 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		skip_spaces(char **str);
static int		is_num(char c);
static int		is_negative(char **str);
int				ft_atoi(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int	negative;
	int	res;

	skip_spaces((char **)&nptr);
	negative = is_negative((char **)&nptr);
	res = 0;
	while (is_num((char)*nptr))
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
	}
	if (negative)
	{
		return (res * -1);
	}
	return (res);
}

static void	skip_spaces(char **str)
{
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
	{
		(*str)++;
	}
}

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static int	is_negative(char **str)
{
	int	res;

	res = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
		{
			res++;
		}
		(*str)++;
	}
	return (res);
}
