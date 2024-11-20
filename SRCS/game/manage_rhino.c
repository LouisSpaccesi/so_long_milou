/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rhino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:49:12 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/19 23:01:30 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	moov_rhino_up(t_data *data)
{
	if (ft_strchr("1EC", data->map[data->r.x - 1][data->r.y]))
		return (0);
	replace_w_img(data, data->r.x * 48, data->r.y * 48, data->background);
	data->r.x--;
	mlx_put_image_to_window(data->mlx, data->win, data->rhino, data->r.y* 48, data->r.x * 48);
	check_for_rhino(data);
	return (1);
}

int	moov_rhino_down(t_data *data)
{
	if (ft_strchr("1EC", data->map[data->r.x + 1][data->r.y]))
		return (0);
	replace_w_img(data, data->r.x * 48, data->r.y * 48, data->background);
	data->r.x++;
	mlx_put_image_to_window(data->mlx, data->win, data->rhino, data->r.y* 48, data->r.x* 48);
	check_for_rhino(data);
	return (1);
}

int	moov_rhino_left(t_data *data)
{
	if (ft_strchr("1EC", data->map[data->r.x][data->r.y - 1]))
		return (0);
	replace_w_img(data, data->r.x * 48, data->r.y * 48, data->background);
	data->r.y--;
	mlx_put_image_to_window(data->mlx, data->win, data->rhino, data->r.y* 48, data->r.x* 48);
	check_for_rhino(data);
	return (1);
}

int	moov_rhino_right(t_data *data)
{
	if (ft_strchr("1EC", data->map[data->r.x][data->r.y + 1]))
		return (0);
	replace_w_img(data, data->r.x * 48, data->r.y * 48, data->background);
	data->r.y++;
	mlx_put_image_to_window(data->mlx, data->win, data->rhino, data->r.y* 48,data->r.x* 48);
	check_for_rhino(data);
	return (1);
}

void	moov_rhino(t_data *data)
{
	int	dir;
	int	mooved;
	
	mooved = 0;
	while (!mooved)
	{
		dir = 1 + rand() % 5;
		if (dir == 1)
			mooved += moov_rhino_up(data);
		if (dir == 2)
			mooved += moov_rhino_down(data);
		if (dir == 3)
			mooved += moov_rhino_right(data);
		if (dir == 4)
			mooved += moov_rhino_left(data);
	}
}