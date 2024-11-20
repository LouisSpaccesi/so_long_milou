/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:39:49 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/18 01:02:18 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	nb_items(t_data *data)
{
	int		c;
	int		i;
	char	**map;

	c = 0;
	map = data->map;
	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] == 'C')
				c++;
			i++;
		}
		map++;
	}
	return (c);
}

void	getdata(t_data *data, char **tab)
{
	t_player	player;
	t_start		s;
	t_end		e;

	e.x = get_x_items(tab, 'E');
	e.y = get_y_items(tab, 'E');
	data->map = tab;
	player.x = get_x_items(tab, 'P');
	player.y = get_y_items(tab, 'P');
	s.x = player.x;
	s.y = player.y;
	data->e = e;
	data->s = s;
	data->p = player;
	data->max_y = ft_strllen(tab[0]);
	data->max_x = nb_line(tab);
	data->nb_items = nb_items(data);
}
