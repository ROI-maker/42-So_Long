/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclaeys <sclaeys@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:48:16 by sclaeys           #+#    #+#             */
/*   Updated: 2025/09/14 01:56:42 by sclaeys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_c(const char s, char c)
{
	return (s == c);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_is_c(*s, c))
			s++;
		if (*s)
		{
			count++;
			while (*s && !ft_is_c(*s, c))
				s++;
		}
	}
	return (count);
}

static char	*ft_malloc_word(char const *s, char c)
{
	char	*word;
	int		word_len;

	word = NULL;
	word_len = 0;
	while (s[word_len] && !ft_is_c(s[word_len], c))
		word_len++;
	word = malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, word_len);
	word[word_len] = '\0';
	return (word);
}

static int	ft_extract_word(char **dest, const char **s, char c, int *i)
{
	dest[*i] = ft_malloc_word(*s, c);
	if (!dest[*i])
	{
		while (*i > 0)
		{
			free(dest[*i - 1]);
			(*i)--;
		}
		return (0);
	}
	(*i)++;
	while (**s && !ft_is_c(**s, c))
		(*s)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		n_of_words;
	int		i;

	n_of_words = ft_count_words(s, c);
	dest = malloc(sizeof(char *) * (n_of_words + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_is_c(*s, c))
			s++;
		if (*s)
		{
			if (!ft_extract_word(dest, &s, c, &i))
			{
				free(dest);
				return (NULL);
			}
		}
	}
	dest[i] = NULL;
	return (dest);
}
