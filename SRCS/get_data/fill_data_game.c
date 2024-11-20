/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:32:56 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/20 01:42:36 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void *init(void *mlx, char *s)
{
	void *img;
	int	w;
	
	w = 48;
    img = mlx_png_file_to_image(mlx, s, &w, &w);
	return (img);
}

void	get_numbers(t_data *data)
{
	data->numbers[0] = init(data->mlx, "textures/numbers/0.png");	
	data->numbers[1] = init(data->mlx, "textures/numbers/1.png");
	data->numbers[2] = init(data->mlx, "textures/numbers/2.png");
	data->numbers[3] = init(data->mlx, "textures/numbers/3.png");
	data->numbers[4] = init(data->mlx, "textures/numbers/4.png");
	data->numbers[5] = init(data->mlx, "textures/numbers/5.png");
	data->numbers[6] = init(data->mlx, "textures/numbers/6.png");
	data->numbers[7] = init(data->mlx, "textures/numbers/7.png");
	data->numbers[8] = init(data->mlx, "textures/numbers/8.png");
	data->numbers[9] = init(data->mlx, "textures/numbers/9.png");
}


void	fill_data(t_data *data)
{
	data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, (data->max_y - 1) * 48, data->max_x * 48, "so_long");
	data->walls = init(data->mlx, "textures/walls.png");
	data->items = init(data->mlx, "textures/items.png");
	data->exit = init(data->mlx, "textures/exit.png"); 
	data->player[1] = init(data->mlx, "textures/player/face.png");
	data->player[0] = init(data->mlx, "textures/player/crouch.png");
	data->background = init(data->mlx, "textures/background.png");
	data->rhino = init(data->mlx, "textures/rhino.png");
	get_numbers(data);
}