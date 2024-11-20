/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:45:02 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/14 15:56:46 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save_lst;
	t_list	*save_next;

	if (!lst)
		return ;
	save_lst = *lst;
	while (save_lst)
	{
		save_next = save_lst->next;
		ft_lstdelone(save_lst, del);
		save_lst = save_next;
	}
	*lst = NULL;
}
