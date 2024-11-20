/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:35:26 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/18 02:26:46 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	c_fill(t_data *data, char *exit_item, t_stack *stack, char *seen)
{
	if (exit_item[1] != data->nb_items || exit_item[0] != 1)
	{
		free(stack);
		free(seen);
		return (0);
	}
	free(stack);
	free(seen);
	return (1);
}

static void	fill_map(t_data *data, t_stack *stack, char *seen, char *exit_item)
{
	int		i;
	t_stack	p;

	i = 0;
	stack[i++] = (t_stack){data->s.x, data->s.y};
	p = stack[0];
	while (i > 0 && data->map[p.x][p.y])
	{
		p = stack[--i];
		if (data->map[p.x][p.y] == '1')
			continue ;
		if (seen[p.x * data-> max_y + p.y])
			continue ;
		seen[p.x * data-> max_y + p.y] = 1;
		if (data->map[p.x][p.y] == 'C')
			exit_item[1]++;
		if (data->map[p.x][p.y] == 'E')
			exit_item[0]++;
		if (i + 4 >= data-> max_x * data->max_y)
			continue ;
		stack[i++] = (t_stack){p.x + 1, p.y};
		stack[i++] = (t_stack){p.x - 1, p.y};
		stack[i++] = (t_stack){p.x, p.y + 1};
		stack[i++] = (t_stack){p.x, p.y - 1};
	}
}

int	flood_fill(t_data *data)
{
	t_stack	*stack;
	char	*seen;
	char	exit_item[2];

	if (data->s.x == -1)
		return (0);
	stack = malloc(data->max_y * data->max_x * sizeof(t_stack));
	if (!stack)
		return (0);
	seen = ft_calloc(data->max_y * data->max_x, 1);
	if (!seen)
	{
		free(stack);
		return (0);
	}
	exit_item[0] = 0;
	exit_item[1] = 0;
	fill_map(data, stack, seen, exit_item);
	return (c_fill(data, exit_item, stack, seen));
}
