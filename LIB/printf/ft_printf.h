/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:25 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/22 22:46:36 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEXA_LOWER "0123456789abcdef" 
# define HEXA_UPPER "0123456789ABCDEF"

int		ft_putnbr_hexa(unsigned long long nb, int i);
int		ft_printf(const char *argv, ...);
int		ft_putchar(char c);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_adress_hexa(void *a);
char	*ft_strchr(const char *s, int c);

#endif