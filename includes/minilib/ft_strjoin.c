/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:26 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/16 00:38:42 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	dest_size;

	if (!s1 && !s2)
		return (ft_calloc(1, 1));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		dest_size = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * (dest_size + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, dest_size + 1);
	ft_strlcat(dest, s2, dest_size + 1);
	return (dest);
}
