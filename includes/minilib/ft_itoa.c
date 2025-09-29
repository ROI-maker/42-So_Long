/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:47:27 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/14 01:57:08 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_n_is_negative(char *dest, int *n)
{
	if (*n < 0)
	{
		dest[0] = '-';
		if (*n == -2147483648)
		{
			dest[1] = '2';
			*n = 147483648;
		}
		else
			*n = -*n;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		len;

	len = ft_get_len(n);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	len--;
	if (n == 0)
	{
		dest[len] = '0';
		return (dest);
	}
	if (n < 0)
		ft_n_is_negative(dest, &n);
	while (n != 0)
	{
		dest[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (dest);
}
