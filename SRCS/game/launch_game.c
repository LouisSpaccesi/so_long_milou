/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lospacce < lospacce@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:03:01 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/20 01:57:17 by lospacce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void create_map(t_data *data)
{
	put_background(data);
	put_walls_items(data);
	put_player(data, data->player[1]);
	put_rhino(data);
}

void	replace_w_img(t_data *data, int x, int y, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win ,img, y, x);
}

void	replace_in_tab(t_data *data, int x, int y, char c)
{
	data->map[x][y] = c;
}

int	check_update(void *d)
{
	t_data	*data;
	unsigned int	old_nb_moove;
	
	data = (t_data *)d;
	old_nb_moove = data->nb_moove;
	make_action(data, old_nb_moove);
	put_nb_moove(data);
	if (data->repeat++ % 3 == 0)
		moov_rhino(data);
	return (0);
}

void    start_game(t_data *data)
{
	fill_data(data);
	create_map(data);

    mlx_on_event(data->mlx, data->win, MLX_KEYDOWN, key_hook, data);
    mlx_on_event(data->mlx, data->win, MLX_KEYUP, key_hook_up, data);
	mlx_on_event(data->mlx, data->win, MLX_WINDOW_EVENT, windows_hook, data);
	
	mlx_loop_hook(data->mlx, check_update, data);

	mlx_set_fps_goal(data->mlx, 10);
	mlx_loop(data->mlx);

	destroy_all(data);
}


