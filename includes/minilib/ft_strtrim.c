/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:50 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/14 01:56:05 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;

	if (!s1)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	if (!set)
	{
		dest = ft_strdup(s1);
		return (dest);
	}
	start = 0;
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	end --;
	while (end > start && ft_is_set(s1[end], set))
		end--;
	end = end - start + 1;
	dest = ft_substr(s1, start, end);
	return (dest);
}
