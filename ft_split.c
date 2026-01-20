/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:16:59 by masselgu          #+#    #+#             */
/*   Updated: 2026/01/20 10:15:38 by masselgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
