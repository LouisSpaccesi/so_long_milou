/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:50:57 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/29 12:25:33 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long long nb, int i)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = HEXA_LOWER;
	if (i)
		hexa = HEXA_UPPER;
	if (nb > 15)
		len += ft_putnbr_hexa(nb / 16, i);
	len += ft_putchar(hexa[nb % 16]);
	return (len);
}
