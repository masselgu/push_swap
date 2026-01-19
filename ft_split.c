/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:29:48 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/19 12:23:00 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sep(char c, char sep)
{
	return (c == sep);
}

static int	count_words(char const *s, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !is_sep(s[i], sep))
				i++;
		}
	}
	return (count);
}

static char	*word_dup(char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	int		words;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && !is_sep(s[i], c))
				i++;
			res[j++] = word_dup(s, start, i);
		}
	}
	res[j] = (NULL);
	return (res);
}
