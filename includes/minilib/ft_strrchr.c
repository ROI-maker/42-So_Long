/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:47 by sclaeys           #+#    #+#             */
/*   Updated: 2025/04/28 15:55:41 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (1)
	{
		if (*s == (unsigned char)c)
			temp = (char *)s;
		if (*s == '\0')
		{
			break ;
		}
		s++;
	}
	return (temp);
}
