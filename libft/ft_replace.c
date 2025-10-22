/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 03:26:08 by gustaoli          #+#    #+#             */
/*   Updated: 2025/10/13 06:50:24 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_replace(char *str, char *target, char *value);
static int	calculate_replaced_str_size(char *str, char *target, char *value);
static void	build_replaced_new_str(char *res, char *str,
				char *target, char *value);

/*
Replace a string inside a string for another string
(return a new allocated str)
ex: "loremabcipsum" "abc" " " => "lorem ipsum"
ex: "arg1;arg2;agr3" ";" "" => "arg1arg2arg3"
ex: "iminlv$" "$" "withaplague" => "iminlvwithaplague"
*/

char	*ft_replace(char *str, char *target, char *value)
{
	char	*res;
	int		total_size;

	if (!str || !*str || !target || !*target)
		return (ft_strdup(str));
	total_size = calculate_replaced_str_size(str, target, value);
	res = ft_calloc(total_size, sizeof(char));
	if (!res)
		return (NULL);
	build_replaced_new_str(res, str, target, value);
	return (res);
}

static int	calculate_replaced_str_size(char *str, char *target, char *value)
{
	int		i;
	int		j;
	int		total_size;
	int		value_size;
	int		target_size;

	i = 0;
	total_size = 0;
	value_size = ft_strlen(value);
	target_size = ft_strlen(target);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == target[j])
			j++;
		if (j == target_size)
		{
			total_size += value_size;
			i += target_size - 1;
		}
		else
			total_size++;
		i++;
	}
	return (total_size + 1);
}

static void	build_replaced_new_str(char *res, char *str,
		char *target, char *value)
{
	int		i;
	int		j;
	int		res_size;
	int		value_size;
	int		target_size;

	i = 0;
	value_size = ft_strlen(value);
	target_size = ft_strlen(target);
	res_size = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == target[j])
			j++;
		if (j == target_size)
		{
			ft_strlcat(res, value, res_size + value_size + 1);
			i += target_size - 1;
			res_size += value_size;
		}
		else
			res[res_size++] = str[i];
		i++;
	}
}
