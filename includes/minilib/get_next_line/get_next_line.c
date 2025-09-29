/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:05:32 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/14 01:58:41 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_line(int fd, char **tmp, char *buff)
{
	int		n_bytes;
	char	*result;
	char	*tmp_new;

	n_bytes = 1;
	result = NULL;
	while (n_bytes > 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes < 0)
		{
			free(*tmp);
			*tmp = NULL;
			return (NULL);
		}
		buff[n_bytes] = '\0';
		tmp_new = ft_strjoin(*tmp, buff);
		free(*tmp);
		*tmp = tmp_new;
		result = ft_split_line_from_tmp(tmp);
		if (result)
			return (result);
	}
	return (NULL);
}

char	*ft_split_line_from_tmp(char **tmp)
{
	char	*newline;
	char	*line;
	char	*rest;
	size_t	pos;

	newline = ft_strchr(*tmp, '\n');
	if (!newline)
		return (NULL);
	pos = newline - *tmp;
	line = ft_substr(*tmp, 0, pos + 1);
	rest = ft_substr(*tmp, pos + 1, ft_strlen(*tmp) - pos - 1);
	free(*tmp);
	*tmp = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;
	char		*result;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!tmp)
		tmp = ft_substr("", 0, 0);
	result = read_until_line(fd, &tmp, buff);
	free(buff);
	if (result)
		return (result);
	if (tmp && *tmp)
	{
		result = ft_substr(tmp, 0, ft_strlen(tmp));
		free(tmp);
		tmp = NULL;
		return (result);
	}
	free(tmp);
	tmp = NULL;
	return (NULL);
}
