/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:01:13 by gustaoli          #+#    #+#             */
/*   Updated: 2025/07/31 19:47:08 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*res_last;

	if (!lst)
		return ((void *) 0);
	res = ft_lstnew(f(lst->content));
	if (!res)
	{
		del(res);
		return ((void *) 0);
	}
	res_last = res;
	while (lst->next)
	{
		lst = lst->next;
		res_last->next = ft_lstnew(f(lst->content));
		if (!res_last->next)
		{
			ft_lstclear(&res, del);
			return ((void *) 0);
		}
		res_last = res_last->next;
	}
	return (res);
}
