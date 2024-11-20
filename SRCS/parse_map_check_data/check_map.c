/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:00 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/18 02:30:58 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	find_start(t_data *data)
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
			if ((*map)[i] == 'P')
				c++;
			i++;
		}
		map++;
	}
	return (c == 1);
}

int	check_format(char **tab)
{
	int	x;
	int	y;
	int	save_y;

	save_y = 0;
	x = -1;
	while (tab[0][save_y])
		save_y++;
	y = 0;
	while (tab[++x])
	{
		while (tab[x][y])
			y++;
		if (!ft_strchr(tab[x], '\n'))
			y++;
		if (y != save_y)
			return (0);
		y = 0;
	}
	return (1);
}
int	find_possible_exit(t_data *data)
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
			if ((*map)[i] == 'E')
				c++;
			i++;
		}
		map++;
	}
	return (c == 1);
}

int	find_exit(t_data *data)
{
	if (!find_possible_exit(data))
		return (0);	
	if (data->s.x == -1 || !flood_fill(data))
		return (0);
	return (1);
}

int	check_data(t_data *data)
{
	if (data->max_y <= 2 || data->s.x == -1 || data->nb_items == 0 || data->e.x == -1)
		return (0);
	return (1);
}
