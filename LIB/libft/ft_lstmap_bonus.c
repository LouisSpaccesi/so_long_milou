/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:06:13 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/15 12:08:11 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*save_new_lst;
	t_list	*cpy_lst;

	if (!lst || !f || !del)
		return (NULL);
	save_new_lst = NULL;
	while (lst)
	{
		cpy_lst = ft_lstnew(f(lst->content));
		if (!cpy_lst)
		{
			del(cpy_lst);
			ft_lstclear(&save_new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&save_new_lst, cpy_lst);
		lst = lst->next;
	}
	return (save_new_lst);
}
