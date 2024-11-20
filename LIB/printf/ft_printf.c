/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:25:40 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/22 23:47:05 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	send_args(char *av, va_list lst)
{
	if (*av == '%' && *av++ && ft_strchr("cspduixX%", *av))
	{
		if (*av == 'c')
			return (ft_putchar(va_arg(lst, int)));
		if (*av == 's')
			return (ft_putstr(va_arg(lst, char *)));
		if (*av == 'p')
			return (ft_adress_hexa(va_arg(lst, void *)));
		if (*av == 'd' || *av == 'i')
			return (ft_putnbr(va_arg(lst, int)));
		if (*av == 'u')
			return (ft_putnbr_unsigned(va_arg(lst, unsigned int)));
		if (*av == 'x')
			return (ft_putnbr_hexa(va_arg(lst, unsigned int), 0));
		if (*av == 'X')
			return (ft_putnbr_hexa(va_arg(lst, unsigned int), 1));
		if (*av == '%')
			return (write(1, "%", 1));
	}
	return (-1);
}

static int	abs(int c)
{
	return (c * ((c > 0) - (c < 0)));
}

int	ft_printf(const char *argv, ...)
{
	int		len;
	int		result;
	va_list	lst;
	char	*av;

	if (!argv)
		return (-1);
	len = 0;
	result = 0;
	va_start(lst, argv);
	av = (char *)argv;
	while (*av)
	{
		result = send_args(av, lst);
		if (result == -1)
			write (1, av, 1);
		else
			av++;
		len += abs(result);
		av++;
	}
	va_end(lst);
	return (len);
}
