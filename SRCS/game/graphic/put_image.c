/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:42:44 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/20 01:41:03 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void put_background(t_data *data)
{
	int x;
	int	y;
	
	x = 0;
	while (x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->background, y * 48, x * 48);	
			y++;
		}
		x++;
	}
}

void put_walls_items(t_data *data)
{
	int x;
	int	y;
	
	x = 0;
	while (x < data->max_x)
	{
		y = 0;
		while (y < data->max_y)
		{
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->walls, y * 48, x * 48);	
			if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->items, y * 48, x * 48);	
			y++;
		}
		x++;
	}
}
void	put_rhino(t_data *data)
{
    int random_x;
	int	random_y;

	srand(time(NULL));
	random_x = 0;
	random_y = 0;
	while (data->map[random_x][random_y] != '0')
	{
		random_x = rand() % (data->max_x);
		random_y = rand() % (data->max_y);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->rhino, random_y * 48, random_x * 48);
	data->r.x = random_x;
	data->r.y = random_y;
}


void put_player(t_data *data, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img, data->p.y * 48,data->p.x * 48);
}

void put_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->exit, data->e.y * 48,data->e.x * 48);
}