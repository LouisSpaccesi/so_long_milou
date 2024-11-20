/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:55:40 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/19 23:01:37 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	make_action(t_data *data, unsigned int old_nb_moove)
{
	if ((data->pressed[SDL_SCANCODE_W] || data->pressed[SDL_SCANCODE_UP])
		&& !(data->pressed[SDL_SCANCODE_S] || data->pressed[SDL_SCANCODE_DOWN]))
		up_pressed(data);
	if ((data->pressed[SDL_SCANCODE_A] || data->pressed[SDL_SCANCODE_LEFT])
		&& !(data->pressed[SDL_SCANCODE_D] || data->pressed[SDL_SCANCODE_RIGHT]))
		left_pressed(data);
	if ((data->pressed[SDL_SCANCODE_S] || data->pressed[SDL_SCANCODE_DOWN])
		&& !(data->pressed[SDL_SCANCODE_W] || data->pressed[SDL_SCANCODE_UP]))
		down_pressed(data);
	if ((data->pressed[SDL_SCANCODE_D] || data->pressed[SDL_SCANCODE_RIGHT])
		&& !(data->pressed[SDL_SCANCODE_A] || data->pressed[SDL_SCANCODE_LEFT]))
		right_pressed(data);
	if (data->pressed[SDL_SCANCODE_ESCAPE])
		esc_pressed(data);
	if (old_nb_moove != data->nb_moove)
		ft_printf("%d\n", data->nb_moove);
	if (data->nb_items == data->items_picked)
		put_exit(data);
}
void    check_for_rhino(t_data *data)
{
	if (data->p.x == data->r.x && data->p.y == data->r.y)
			mlx_loop_end(data->mlx);
}