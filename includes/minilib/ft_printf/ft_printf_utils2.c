/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:36:22 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/14 01:59:49 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%x && %X
int	ft_puthex(unsigned long long nb, int uppercase)
{
	char	*base;
	int		len;

	len = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb > 15)
		len += ft_puthex(nb / 16, uppercase);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

//%p
int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					len;

	len = 0;
	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex(addr, 0);
	return (len);
}
