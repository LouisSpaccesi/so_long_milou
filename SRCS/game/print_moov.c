/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:56:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/11/19 22:08:33 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	print_number(t_data *data, int nb, int x)
{
	replace_w_img(data, 0, (data->max_y - x - 2) * 48, data->walls);
	mlx_put_image_to_window(data->mlx, data->win, data->numbers[nb], (data->max_y - x - 2) * 48, 0);
	return (1);
}

void	put_nb_moove(t_data *data)
{
	unsigned int	nb_moove_cpy;
	int	b;

	b = 0;
	nb_moove_cpy = data->nb_moove;
	while (nb_moove_cpy >= 10)
	{
		b += print_number(data, nb_moove_cpy % 10, b);
		nb_moove_cpy /= 10;	
	}	
	b += print_number(data, nb_moove_cpy % 10, b);
}