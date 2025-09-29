/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:47:33 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/14 01:57:03 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *) str;
	while (n > 0)
	{
		if (*s1 == (unsigned char)c)
		{
			return ((void *)s1);
		}
		s1++;
		n--;
	}
	return (NULL);
}
