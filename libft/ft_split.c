/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:45:07 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/05/25 23:35:47 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *str, char c)
{
	size_t words;

	words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			words++;
			while (*str && *str != c)
				str++;
		}
	}
	return (words);
}

static char		*ft_word(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void		ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

static char		**ft_words(char *str, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)malloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*str == c)
				str++;
			if (*str)
			{
				if (!(word = ft_word(str, c)))
				{
					ft_free_words(words, i);
					return (NULL);
				}
				words[i++] = word;
				str += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_split(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s || !(line = ft_strdup((char *)s)))
		return (NULL);
	words = ft_words(line, c, ft_count(line, c));
	free(line);
	return (words);
}
