/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:03:16 by vpogorel          #+#    #+#             */
/*   Updated: 2024/11/28 15:47:30 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_free(char **split, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	get_total_words(char const *s, char c, size_t len_s)
{
	size_t	i;
	int		len_word;
	int		total_words;

	i = 0;
	total_words = 0;
	while (i < len_s && i < len_s)
	{
		len_word = 0;
		while (i < len_s && s[i++] != c)
			len_word++;
		if (len_word > 0)
			total_words++;
	}
	return (total_words);
}

static void	allocatwords(char **split, char const *s, char c, size_t len_s)
{
	size_t		i;
	size_t		len_word;
	int			total;
	int			start;

	i = 0;
	total = 0;
	start = 0;
	while (i < len_s)
	{
		len_word = 0;
		start = i;
		while (i < len_s && s[i++] != c)
			len_word++;
		if (len_word > 0)
		{
			split[total] = ft_substr(s, (unsigned int)start, len_word);
			if (split[total] == NULL)
				return (ft_free(split, total));
			total++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	len_s;
	int		total;
	char	**split;

	total = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	total = get_total_words(s, c, len_s);
	split = (char **)malloc(sizeof(char *) * (total + 1));
	if (!split)
		return (NULL);
	allocatwords(split, s, c, len_s);
	if (split == NULL)
		return (NULL);
	split[total] = NULL;
	return (split);
}
