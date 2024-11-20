/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:34:43 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/22 22:57:54 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"

int	ft_adress_hexa(void *a)
{
	if (!a)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putnbr_hexa((unsigned long long)a, 0) + 2);
}
