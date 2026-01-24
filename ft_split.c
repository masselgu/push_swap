/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:16:59 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/23 18:20:22 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (start >= ft_strlen(s))
	{
		substring = malloc(1);
		if (!substring)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	i = 0;
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

static	int	count_words(const char *s, char c)
{
	int		count;
	int		word;
	size_t	i;

	word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static int	fill_words(char **res, char const *s, char c, int word_count)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		res[i] = ft_substr(s, start, j - start);
		if (!res[i])
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		err;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	err = fill_words(res, s, c, word_count);
	if (err >= 0)
	{
		while (err--)
			free(res[err]);
		free(res);
		return (NULL);
	}
	res[word_count] = NULL;
	return (res);
}
