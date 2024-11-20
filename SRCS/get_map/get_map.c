/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:02:36 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/18 01:02:19 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	nb_line_fd(int fd, t_list *lst)
{
	t_list	*cpy_line;
	int		nb;

	nb = 0;
	cpy_line = lst;
	while (cpy_line->content)
	{
		cpy_line = ft_lstnew(get_next_line(fd));
		if (!cpy_line)
			return (0);
		ft_lstadd_back(&lst, cpy_line);
		nb++;
	}
	close(fd);
	return (nb);
}

void	*free_lst(t_list *lst)
{
	t_list	*cpy;

	cpy = NULL;
	while (lst)
	{
		cpy = lst->next;
		free(lst);
		lst = cpy;
	}
	return (NULL);
}

char	**get_map(int fd)
{
	char	**map;
	int		nb_lines;
	t_list	*lst;
	t_list	*save_lst;
	int		i;

	lst = ft_lstnew("");
	nb_lines = nb_line_fd(fd, lst);
	if (!nb_lines)
		return (free_lst(lst));
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	save_lst = lst;
	while (lst->next)
	{
		lst = lst->next;
		map[i] = lst->content;
		i++;
	}
	free_lst(save_lst);
	return (map);
}
