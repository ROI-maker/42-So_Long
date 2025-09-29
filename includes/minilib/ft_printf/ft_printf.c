/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:55:25 by sclaeys           #+#    #+#             */
/*   Updated: 2025/06/16 16:37:12 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		n_of_char;
	int		i;
	va_list	args;

	i = 0;
	n_of_char = 0;
	va_start(args, str);
	while (str[i])
	{
		if ((str[i] == '%' ) && (str[i + 1] && str[i + 1] != '%'))
		{
			i++;
			n_of_char += handle_conversion(str[i], args);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			i++;
			n_of_char += ft_putchar('%');
		}
		else
			n_of_char += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (n_of_char);
}
